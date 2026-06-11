#include <bits/stdc++.h>
using namespace std;

const int EDGE_CASE = 1e9;

int main(){
    int N, K, S;
    scanf("%d%d%d", &N, &K, &S);

    if(S == EDGE_CASE){
        for(int i = 0; i < K; i ++){
            printf("%d", EDGE_CASE);
            if(i != N-1){
                printf(" ");
            }
        }

        for(int i = K; i < N; i ++){
            printf("1");
            if(i != N-1){
                printf(" ");
            }
        }

        return 0;
    }else if(S == 1){
        for(int i = 0; i < K; i ++){
            printf("1");
            if(i != N-1){
                printf(" ");
            }
        }

        for(int i = K; i < N; i ++){
            printf("%d", EDGE_CASE);
            if(i != N-1){
                printf(" ");
            }
        }
    }else if(K == N){
        for(int i = 0; i < N; i ++){
            printf("%d", S);
            if(i != N-1){
                printf(" ");
            }
        }
    }else{
        for(int i = 0; i <= K; i ++){
            if(i%2 == 0){
                printf("1");
            }else{
                printf("%d", S-1);
            }
            if(i != N-1){
                printf(" ");
            }
        }

        for(int i = K+1; i < N; i ++){
            printf("%d", EDGE_CASE);
            if(i != N-1){
                printf(" ");
            }
        }
    }
}


