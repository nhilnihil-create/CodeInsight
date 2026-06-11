#include <iostream>
using namespace std;
long long N, M, K;
long long As[200005];
long long Bs[200005];
long long aim[200005];
int main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    long long s = 0;
    int length = 1;
    aim[0] = K;
    for(int i = 1; i <= N; ++i){
        scanf("%lld",&As[i]);
        s+=As[i];
        if(s > K)
            continue;
        
        length++;
        aim[i] = K - s;
            
    }
    if(length == -1)
        length = N+1;

    s = 0;
    int maxN = length-1;
    int ptr = length -1;
    for(int i = 1; i <= M; ++i){
        scanf("%d",&Bs[i]);
        
        if(s > K)
            continue;

        s += Bs[i];

        while(ptr >= 0 && s > aim[ptr] )
            ptr--;
        
        if (ptr >= 0)
            maxN = max(maxN,ptr+i);
    }

    printf("%d\n",maxN);
}