#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<30;i++){
        if(N==(1<<i)) {printf("No\n"); return 0;}
    }

    printf("Yes\n");
    printf("%d %d\n", N+1, N+3);
    for(int i=3;i<=N;i+=2){
        printf("%d %d\n", 1, i);
        printf("%d %d\n", 1, i-1);
        printf("%d %d\n", i, i+N-1);
        printf("%d %d\n", i-1, i+N);
    }

    if(N%2==0){
        for(int i=2;i<N;i++){
            if(((N+1)^i)<N){
                printf("%d %d\n", i, N);
                printf("%d %d\n", (N+1)^i, 2*N);
                break;
            }
        }
    }
    
    return 0;
}