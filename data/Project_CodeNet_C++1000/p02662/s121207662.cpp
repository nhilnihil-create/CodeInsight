#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll/*, vl, greater<ll>*/> pql; //降順(/*昇順*/)
typedef set<ll> sl;
typedef pair<ll, ll> pl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, n) for(ll i = 1; i <= ll(n); i++)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); i++)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); i++)
#define all(v) (v).begin(), (v).end()
bool chmin(ll &a, ll b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const ll MAX = 3001;
const char newl = '\n';

ll modpow(ll n) {
  if(n==0) return 1;
  else if(n%2==0) return modpow(n/2)*modpow(n/2)%MOD;
  else return 2*modpow(n-1)%MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, s;
  cin >> n >> s;
  
  ll a, start = modpow(n-1), inv2 = modpow(MOD-2);
  
  vvl dp(n+1, vl(s+1, 0));
  rep(i, n) {
    cin >> a;
    if(a<=s) dp[i+1][a] = start;
    rep2(j, s) {
      dp[i+1][j] += dp[i][j];
      if(j-a>=0) dp[i+1][j] += dp[i][j-a]*inv2;
      dp[i+1][j] %= MOD;
    }
  }
  cout << dp[n][s] << newl;
  return 0;
}