#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
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

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll k;
  cin >> k;

  vector<ll> lu;
  queue<ll> q;

  for (int i = 1; i <= 9; i++) {
    lu.push_back(i);
    q.push(i);
  }

  while (lu.size() < k && !q.empty()) {
    ll n = q.front(); q.pop();
    ll b = n % 10;
    ll ne = n * 10;
    if (b != 0) {
      lu.push_back(ne + b - 1LL);
      q.push(ne + b - 1LL);
    }
    lu.push_back(ne + b);
    q.push(ne + b);
    if (b != 9) {
      lu.push_back(ne + b + 1LL);
      q.push(ne + b + 1LL);
    }
  }

  cout << lu[k-1] << endl;

  return 0;
}
