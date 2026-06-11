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

using P = pair<int, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<P> c;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    c.push_back({x, y});
  }

  double sum = 0.0;

  vector<int> order(n);
  rep(i, n) order[i] = i;
  int num = 0;

  do {
    num++;
    double x = 0.0;
    for (int i = 0; i < n - 1; i++) {
      x += sqrt(pow(c[order[i]].first - c[order[i+1]].first, 2) + pow(c[order[i]].second - c[order[i+1]].second, 2));
    }
    sum += x;
  } while (next_permutation(order.begin(), order.end()));

  printf("%.10lf\n", sum / num);

  return 0;
}
