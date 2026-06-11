#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pint pair<int,int>
typedef long long lint;

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);
    int A[N];
    rep(i,N) scanf("%d",&A[i]);
    rep(i,N) A[i]--;
    pint Sum[N+1]={};
    Sum[0].first=0,Sum[0].second=0;
    rep(i,N){
        Sum[i+1].first=(Sum[i].first+A[i])%K;
        Sum[i+1].second=i+1;
    }
    lint ans=0;
    sort(Sum,Sum+N+1);
    int num=Sum[0].first,count=0;
    int las=0,top=1;
    int begsave=0;
    for(int i=0;i<=N;i++){
        if(Sum[i].first==num) count++,top=Sum[i].second;
        else{
            count=1,num=Sum[i].first;las=Sum[i].second;
            begsave=i;
            continue;
        }
        if(top-las>=K){
            while(top-las>=K){
                count--;
                begsave++;
                las=Sum[begsave].second;
            }
        }
        ans+=count-1;
    }
    printf("%lld\n",ans);
}