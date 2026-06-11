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
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

ll calc_num_of_combination(ll n, ll r) {
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  string r = s;
  reverse(ALL(r));

  vector<ll> a; a.reserve(s.size());

  int mul = 1;
  for (char& c : r) {
    ll v = c - '0';
    v *= mul;
    v %= 2019;
    a.push_back(v);
    mul *= 10;
    mul %= 2019;
  }

  vector<ll> su(a.size(), 0);
  su[0] = a[0];
  for (int i = 1; i < su.size(); i++) {
    su[i] = su[i-1] + a[i];
    su[i] %= 2019;
  }

  map<ll, int> mp;
  mp[0]++;
  for (auto& x : su) {
    mp[x]++;
  }

  ll ans = 0;
  for (auto& p : mp) {
    if (p.second < 2) continue;
    ans += calc_num_of_combination(p.second, 2);
  }

  cout << ans << endl;

  return 0;
}
