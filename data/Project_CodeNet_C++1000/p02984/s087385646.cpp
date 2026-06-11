#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> minus(N), plus(N);
  minus[0] = -A[0], plus[0] = A[0];
  REP(i, N - 1) {
    int j = i + 1;
    if (j % 2 == 0) {
      minus[j] = minus[i] - A[j];
      plus[j] = plus[i] + A[j];
    } else {
      minus[j] = minus[i] + A[j];
      plus[j] = plus[i] - A[j];
    }
  }
  cout << plus[N-1] << endl;
  for (int i = 1; i < N; i++) {
    if (i % 2 == 0) {
      ll t1 = plus[N - 1] - plus[i-1];
      ll t2 = minus[i - 1];
      cout << t1 + t2 << endl;
    } else {
      ll t1 = minus[N - 1] - minus[i-1];
      ll t2 = plus[i - 1];
      cout << t1 + t2 << endl;
    }
  }
}