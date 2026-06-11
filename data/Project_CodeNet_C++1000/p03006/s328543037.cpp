#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main(int argc, char* argv[])
{
  int n;
  cin >> n;
  vector<pair<ll, ll>> pos(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    pos[i] = make_pair(x, y);
  }

  map<pair<ll, ll>, int> m;
  for (int i = 0; i < n; i++) {
    auto pos1 = pos[i];
    for (int j = i+1; j < n; j++) {
      auto pos2 = pos[j];
      auto d1 = make_pair(pos1.first - pos2.first, pos1.second - pos2.second);
      auto d2 = make_pair(pos2.first - pos1.first, pos2.second - pos1.second);
      m[d1]++;
      m[d2]++;
    }
  }

  int tmp = 0;
  for (auto& v : m) {
    chmax(tmp, v.second);
  }

  cout << n - tmp << endl;

  return 0;
}
