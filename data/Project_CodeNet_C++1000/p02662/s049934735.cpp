#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 998244353;
const int INF = 1e9;
const ll INFLONG = 1e18;


int main(){
  ll n,s;
  cin >> n >> s;
  vector<ll> A(n);
  vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
  vector<vector<ll>> sum(n+1,vector<ll>(s+1,0));
  dp[0][0] = 1;
  rep(i,n){
    cin >> A[i];
  }
  rep(i,n){
    rep(j,s+1){
      dp[i+1][j] = 2 * dp[i][j];
      dp[i+1][j] %= mod;
      if(j - A[i] >= 0){
        dp[i+1][j] += dp[i][j-A[i]];
        dp[i+1][j] %= mod;
      }
    }
  }
  cout << dp[n][s] << endl;
}