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
  vector<P> A(N);
  REP(i, N) { cin >> A[i].second >> A[i].first; }
  sort(A.begin(), A.end());
  ll now = 0;
  bool ok = true;
  REP(i, N) {
    now += A[i].second;
    if (A[i].first < now) {
      ok = false;
    }
  }
  printf(ok ? "Yes" : "No");
  cout << "\n";
}