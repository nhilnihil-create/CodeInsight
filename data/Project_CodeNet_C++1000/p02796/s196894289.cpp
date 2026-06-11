#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};

int main() {
  int N;
  cin >> N;
  vector<P> X(N);
  REP(i, N) cin >> X[i].first >> X[i].second;
  vector<P> ps(N);
  REP(i, N) { ps[i] = P(X[i].first + X[i].second, X[i].first - X[i].second); }
  sort(ps.begin(), ps.end());
  int cur = -1000000000;
  int ans = 0;
  REP(i, N) {
    if (cur <= ps[i].second) {
      ans++;
      cur = ps[i].first;
    }
  }
  cout << ans << endl;
}