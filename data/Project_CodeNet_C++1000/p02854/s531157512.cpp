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
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> ruiseki(N);
  ruiseki[0] = A[0];
  for (int i = 1; i < N; i++) {
    ruiseki[i] = A[i] + ruiseki[i - 1];
  }
  ll mn = 1e16;
  REP(i, N) {
    ll left = ruiseki[i], right = ruiseki[N - 1] - ruiseki[i];
    mn = min(mn, abs(left-right));
  }
  cout << mn << endl;
}