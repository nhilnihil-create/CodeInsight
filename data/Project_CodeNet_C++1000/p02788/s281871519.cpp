#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,D,A; cin >> N >> D >> A;
  vector<P> AS(N);
  rep(i, N) {
    cin >> AS[i].first >> AS[i].second;
    AS[i].second = (AS[i].second + A - 1) / A;
  }
  sort(AS.begin(), AS.end(), [&](P &a, P &b) {
    return a.first < b.first;
  });
  vector<P> bombs;

  ll ans = 0;
  ll nums = 0;
  int bf = 0;
  rep(i, N) {
    int x = AS[i].first;
    int h = AS[i].second;

    while(bombs.size() > bf) {
      auto &bomb = bombs[bf];
      if(bomb.first + D < x) {
        ++bf;
        nums -= bomb.second;
        continue;
      } else {
        break;
      }
    }

    h -= nums;
    if(h <= 0) continue;

    ans += h;
    bombs.push_back({x + D, h});
    nums += h;
  }

  cout << ans << endl;
}
