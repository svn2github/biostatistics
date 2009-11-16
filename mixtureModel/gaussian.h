/*
 * Parameters file for gaussian mixture model based clustering application
 */

#ifndef GAUSSIAN_H
#define GAUSSIAN_H

// Maxinum number of threads per block is 512, so that limits us to 512 clusters
// Probably will run out of memory and make the computation intractable far before 512 clusters though
#define MAX_CLUSTERS 512
#define PI  3.1415926535897931
#define	NUM_BLOCKS 24 
#define NUM_THREADS 256
#define NUM_DIMENSIONS 24

// Maximum number of iterations for the EM convergence loop
#define MAX_ITERS 1000

// Prints verbose output during the algorithm
// Enables the DEBUG macro
#define ENABLE_DEBUG 1

// Used to enable regular print outs (such as the Rissanen scores, clustering results)
// This should be enabled for general use and disabled for performance evaluations only
#define ENABLE_PRINT 1

// Used to enable EMUPRINT macro, this can only be used when compiled for
// in emulation mode. It is used to print out during cuda kernels
#define EMU 0

#if ENABLE_DEBUG
#define DEBUG(fmt,args...) printf(fmt, ##args)
#else
#define DEBUG(fmt,args...)
#endif

#if ENABLE_PRINT
#define PRINT(fmt,args...) printf(fmt, ##args)
#else
#define PRINT(fmt,args...)
#endif

#ifdef EMU
#define EMUPRINT(fmt,args...) printf(fmt, ##args)
#else
#define EMUPRINT(fmt,args...)
#endif

typedef struct 
{
    float N;        // expected # of pixels in cluster
    float pi;       // probability of cluster in GMM
    float *means;   // Spectral mean for the cluster
    float *R;      // Covariance matrix
    float *Rinv;   // Inverse of covariance matrix
    float avgvar;    // average variance
    float constant; // Normalizing constant
    float *p;       // Probability that each pixel belongs to this cluster
} cluster;

int validateArguments(int argc, char** argv, int* num_clusters, FILE** infile, FILE** outfile);
void printUsage(char** argv);
#endif

