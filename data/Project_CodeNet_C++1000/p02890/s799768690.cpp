#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main() {
    int N, A;
    scanf("%d",&N);

    int Cj[N+1], Dk[N+1];
    memset(Cj, 0, sizeof(int)*(N+1));
    memset(Dk, 0, sizeof(int)*(N+1));
    
    int i;
    for (i=0; i<N; i++) {
        scanf("%d", &A);
        Cj[A]++;
    }

    int DkSum1=0, DkSum2=0;
    for (i=1; i<=N; i++) {
        Dk[Cj[i]]++;
        DkSum2++;
    }
    DkSum1 = 0;
    DkSum2 -= Dk[0];

    int X, k, FX[N+1];
    FX[0] = INT_MAX;
    for (X=1; X<=N; X++) {
        DkSum1 += X*Dk[X];
        DkSum2 = DkSum2 - Dk[X];
        FX[X] = DkSum1/X + DkSum2;
    }

    int K;
    X = N;
    for (K=1; K<=N; K++) {
        while (K > FX[X])  X--;
        printf("%d\n", X);
    }

    return 0;
}
