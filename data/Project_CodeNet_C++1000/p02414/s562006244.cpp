#include <cstdio>
#include <stdlib.h>

#include <iostream>
#include <chrono>


#define N 10000

#if _DEBUG
typedef long lli;
#else
typedef long long int  lli;
#endif

lli a[N*N];
lli b[N*N];
lli c[N*N];

int n,m,l;

void mult() {
    lli register t;
    for(int i=0; i<n; i++)
        for(int j=0; j<l; j++)
        {
            t = 0;
            for(int k=0; k<m; k++)
                t += a[i*N + k] * b[k*N + j];
            c[i*N + j] = t;
        }
}

int main(void) {
#if _DEBUG
    for(n=2; n<N; n*=2) {
        m=l=n;
#else
        scanf("%d%d%d", &n, &m, &l);
#endif


#if _DEBUG
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                a[i*N + j] = rand();
        for(int i=0; i<m; i++)
            for(int j=0; j<l; j++)
                b[i*N + j] = rand();
#else
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%lld", &a[i*N + j]);
        for(int i=0; i<m; i++)
            for(int j=0; j<l; j++)
                scanf("%lld", &b[i*N + j]);
#endif
        for(int i=0; i<n; i++)
            for(int j=0; j<l; j++)
                c[i*N + j] = 0;

        auto start = std::chrono::system_clock::now();
        mult();
        auto end = std::chrono::system_clock::now();

#if _DEBUG
        auto dur = end-start;
        auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        std::cout << n << " : " << msec << " milli sec" << std::endl;
    }
#else
    for(int i=0; i<n; i++) {
        for(int j=0; j<l-1; j++)
            printf("%lld ", c[i*N + j]);
        printf("%lld", c[i*N + l-1]);
        printf("\n");
    }
#endif
    return 0;
}