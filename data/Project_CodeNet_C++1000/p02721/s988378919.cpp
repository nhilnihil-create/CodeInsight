#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<63)-1
#define MAX 1000000000
signed main(){
    int N,K,C; cin>>N>>K>>C;
    string S; cin>>S;
    vi cp(N+1),dp(N+1);
    REP(i,1,N){
        cp[i]=cp[i-1];
        if(S[i-1]=='o') cp[i]=max(cp[i],cp[max(0ll,i-C-1)]+1);
    }
    REP(i,1,N){
        int j=N-i;
        dp[j]=dp[j+1];
        if(S[j]=='o') dp[j]=max(dp[j],dp[min(N,j+C+1)]+1);
    }
    vii A(K+1);
    rep(i,0,N){
        if(S[i]=='o'){
            //cout<<cp[i+1]<<" "<<dp[i]<<endl;
            if(cp[i+1]+dp[i]==K+1) A[cp[i+1]].pb(i+1);
        }
    }
    REP(i,1,K){
        if(A[i].size()==1) cout<<A[i][0]<<endl;
    }
}