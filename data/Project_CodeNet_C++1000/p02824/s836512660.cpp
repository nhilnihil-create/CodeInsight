#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<62;
constexpr double eps = (1e-9);

bool isGood(ll& N, ll& M, ll& V, ll& P, vector<ll>& A, ll& x) {
     if (x < P) return true;
     ll now = A[x] + M;
     if (A[P - 1] > now) return false;
     ll score = 0;
     score += (P - 1) * M;
     score += (N - x) * M;
     for (ll i = P - 1; i < x ; i++) {
         score += min(M, max(0LL, now - A[i]));
     }
     return score >= M * V;
 }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  ll lb = p-1;
  ll ub = n;

  while (ub - lb > 1) {
    ll mid = lb + (ub - lb) / 2;
    if (isGood(n, m, v, p, a, mid)) lb = mid;
    else ub = mid;
  }

  cout << lb + 1 << endl;

  return 0;
}
