#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
signed main(){
    int N,K;cin>>N>>K;
    int S[N+1];
    REP(i,N+1)S[i]=0;
    REPS(i,N){
        int a;cin>>a;
        S[i]=(S[i-1]+a-1)%K;
        while(S[i]<0)S[i]+=K;
    }
    int ans=0;
    map<int,int>memo;
    REPS(j,N){
        if(j==1){
            for(int i=max(0ll,j-K+1);i<j;i++){
                memo[S[i]]++;
            }
        }
        else{
            if(j-K>=0)memo[S[j-K]]--;
            memo[S[j-1]]++;
        }
        ans+=memo[S[j]];
    }
    cout<<ans<<endl;
}