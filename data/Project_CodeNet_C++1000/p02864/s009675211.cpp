#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n+1,0);
  rep(i,n){
    cin >> a[i+1];
  }
  vector<vector<ll>> dp(310, vector<ll>(310,longinf));
  dp[0][0]=0;
  for(int i=1; i<=n; i++)rep(j,n-k){
    ll tmp = longinf;
    rep(l,i){
      tmp = min(tmp, dp[l][j] + max(0,a[i]-a[l]));
    }
    dp[i][j+1] = tmp;
  }
  ll ans = longinf;
  REP(i,n-k,n+1){
    ans = min(ans, dp[i][n-k]);
  }
  cout << ans << ln;
  return 0;
}