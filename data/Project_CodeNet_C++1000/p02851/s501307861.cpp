#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
    int N,K;
    cin >> N >> K;
    int A[N];
    rep(i,N) cin >> A[i];
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
    cout << ans << endl;
}