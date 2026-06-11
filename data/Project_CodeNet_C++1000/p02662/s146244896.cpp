#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7,MOD=998244353;

int main() {
  int N,S;
  cin >> N >> S;
  vi A(N);
  rep(i,N) cin >> A[i];
  
  vvi dp(N+1,vi(S+1));
  dp[0][0]=1;
  rep(i,N) {
    rep(j,S+1) {
      dp[i+1][j]=dp[i][j]*2%MOD;
      if(j>=A[i]) dp[i+1][j]=(dp[i+1][j]+dp[i][j-A[i]])%MOD;
    }
  }
  
  cout << dp[N][S] << endl;
}