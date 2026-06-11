#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, int>Pair;
#define MAX 1e9
struct edge { int to, cost; };
typedef pair<int, int>P;
#define MOD 1000000007

int main(){
  string S;
  cin>>S;
  ll N=S.size();
  ll dp[N+1][2];
  rep(i,N+1){dp[i][0]=0ll;dp[i][1]=0ll;}
  dp[0][1]=1ll;
  rep(i,N){
      dp[i+1][0]+=3ll*dp[i][0];
    if(S[i]=='1'){
      dp[i+1][0]+=dp[i][1];
      dp[i+1][1]+=2ll*dp[i][1];
    }
    else{dp[i+1][1]+=dp[i][1];}
    dp[i+1][0]%=MOD;
    dp[i+1][1]%=MOD;
  }
  ll ans=0ll;
  ans+=dp[N][0]+dp[N][1];
  ans%=MOD;
  ans+=MOD;
  ans%=MOD;
  cout<<ans;
}

