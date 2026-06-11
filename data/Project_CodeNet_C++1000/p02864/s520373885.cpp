//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 0xcccccccccccccccLL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

#define N 310

//head

int n, k;
int h[N];
ll dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  rep(i, n) cin >> h[i+1];
  fill(dp[0]+1, dp[n+1], LINF);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      for(int k = j-1; k < i; k++) {
        chmin(dp[i][j], dp[k][j-1] + max(0, h[i]-h[k]));
      }
      //cout << dp[i][j] << (j == i?'\n':' ');
    }
  }
  ll ans = LINF;
  rep(i, n+1) chmin(ans, dp[i][n-k]);
  cout << ans << endl;
}