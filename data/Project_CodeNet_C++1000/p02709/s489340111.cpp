//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
////////////////////////////////////////////////////////////////////

int n, dp[2100][2100];P a[2100];
signed main() {
  cin>>n;rep(i,n)cin>>a[i].first, a[i].second = i;
  sort(a,a+n,greater<P>());
  dp[0][1] = a[0].first*a[0].second;
  dp[0][0] = a[0].first*(n-a[0].second-1);
  repd(i,1,n){
    dp[i][0] = dp[i-1][0] + a[i].first*abs(n-a[i].second-i-1);
    repd(j,1,n+1){
      if(j > i+1)continue;
      int s = n-1-(i-j), t = j-1;
      dp[i][j] = max(dp[i-1][j]+a[i].first*abs(s-a[i].second), dp[i-1][j-1]+a[i].first*abs(t-a[i].second));
    }
  }
  int ans = 0;
  rep(i,n)chmax(ans, dp[n-1][i]);
  cout << ans << endl;
}

