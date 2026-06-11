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
#define INF (1ll<<60)
signed main(){
  string S; cin>>S;
  int N=S.size();
  vii dp(N+1,vi(2));
  dp[0][1]=1;
  rep(i,0,N){
    if(S[i]=='0'){
      dp[i+1][0]=dp[i][0]*3;
      dp[i+1][1]=dp[i][1];
    }
    else{
      dp[i+1][0]=dp[i][0]*3+dp[i][1];
      dp[i+1][1]=dp[i][1]*2;
    }
    dp[i+1][0]%=MOD;
    dp[i+1][1]%=MOD;
  }
  cout<<(dp[N][0]+dp[N][1])%MOD<<endl;
  }

