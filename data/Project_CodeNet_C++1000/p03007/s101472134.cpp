#include <bits/stdc++.h>
using namespace std;

long long A[100005];
long long B[100005];
long long C[100005];

int main(){
    int cntB = 0;
    int cntC = 0;

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%lld", &A[i]);
        if(A[i]<0){
            B[cntB++] = A[i];
        }else{
            C[cntC++] = A[i];
        }
    }

    sort(B, B+cntB);
    sort(C, C+cntC);

    if(cntB && cntC){
        long long sum = 0;
        for(int i = 0; i < N; i ++){
            sum += abs(A[i]);
        }
        printf("%lld\n", sum);

        // use B[0] to eat up all C except the last
        for(int i = 0; i < cntC-1; i ++){
            printf("%lld %lld\n", B[0], C[i]);
            B[0] -= C[i];
        }

        // use C[cntC-1] to eat up all B except the first
        for(int i = 1; i < cntB; i ++){
            printf("%lld %lld\n", C[cntC-1], B[i]);
            C[cntC-1] -= B[i];
        }

        // then use B[0] to eat up C[cntC-1]
        printf("%lld %lld\n", C[cntC-1], B[0]);

        return 0;
    }

    if(cntB){
        // all elements are negative
        // use B[N-1] to eat up everything
        long long sum = B[N-1];
        for(int i = 0; i < N-1; i ++){
            sum += abs(B[i]);
        }

        printf("%lld\n", sum);
        for(int i = 0; i < N-1; i ++){
            printf("%lld %lld\n", B[N-1], B[i]);
            B[N-1] -= B[i];
        }

        return 0;
    }

    if(cntC){
        // all elements are negative
        // use C[0] to eat up everything
        long long sum = -C[0];
        for(int i = 1; i < N; i ++){
            sum += abs(C[i]);
        }

        printf("%lld\n", sum);
        for(int i = 1; i < N-1; i ++){
            printf("%lld %lld\n", C[0], C[i]);
            C[0] -= C[i];
        }

        printf("%lld %lld\n", C[N-1], C[0]);
        return 0;
    }

    return 0;
}
