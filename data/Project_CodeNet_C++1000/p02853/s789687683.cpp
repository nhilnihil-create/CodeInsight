#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF = 1e9;
const long long INFL = 1LL<<60;

int calc(const int& a) {
  if (a == 1) {
    return 300000;
  } else if (a == 2) {
    return 200000;
  } else if (a == 3) {
    return 100000;
  } else {
    return 0;
  }
}

int main()
{
  int x, y;
  cin >> x >> y;
  int ans = 0;
  ans += calc(x);
  ans += calc(y);
  if (x == 1 && y == 1) ans += 400000;

  cout << ans << endl;
  return 0;
}
