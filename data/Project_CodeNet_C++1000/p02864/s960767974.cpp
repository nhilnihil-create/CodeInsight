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
#define INF (1ll<<62)-1
#define MAX 1000000000
signed main(){
    int N,K; cin>>N>>K;
    vi A(N+1);
    REP(i,1,N) cin>>A[i];
    int dp[N+1][K+1][K+1]={0};
    REP(i,1,N){
        REP(j,0,(min(i,K))){
            REP(k,1,j) dp[i][j][k]=dp[i-1][j-1][k-1];
            if(j<i){
                dp[i][j][0]=INF;
                if(j<i-1){
                    REP(k,0,j){
                        dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][k]+max(0ll,A[i]-A[i-1-k]));
                    }
                }
                else dp[i][j][0]=dp[i-1][j][j]+A[i];
            }
        }
    }
    int ans=INF;
    REP(i,0,K) ans=min(ans,dp[N][K][i]);
    cout<<ans<<endl;
}
