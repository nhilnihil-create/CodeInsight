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
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N,M;
  cin >> N >> M;
  vi S(N),T(M);
  rep(i,N) cin >> S[i];
  rep(i,M) cin >> T[i];
  vvi dp(N+1,vi(M+1,1));
  rep(i,N) {
    rep(j,M) {
      ll x=dp[i+1][j]+dp[i][j+1]-dp[i][j];
      if(S[i]==T[j]) x+=dp[i][j];
      dp[i+1][j+1]=(x+INF)%INF;
    }
  }
  
  cout << dp[N][M] << endl;
}