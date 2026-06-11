#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N, K;
  cin >> N >> K;
  vi A(N);
  REP(i, N) cin >> A.at(i);
  if (K > 75) K = 75;

  REP(x, K) {
    vi B(N + 1);
    REP(i, N) {
      int l = max(0, i - A.at(i));
      int r = min(N - 1, i + A.at(i));
      B.at(l)++;
      B.at(r + 1)--;
    }
    A[0] = B[0];
    for (int j = 1; j < N; j++) {
      A[j] = A[j - 1] + B[j];
    }
  }

  REP(k, N) cout << A.at(k) << " ";
  cout << "\n";
  return 0;
}