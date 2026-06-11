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
  vector<int> d(N);
  REP(i, N) cin >> d[i];
  ll ans = 0;
  REP(i, N - 1) for (int j = i + 1; j < N; j++) { ans += d[i] * d[j]; }
  cout << ans << endl;
}