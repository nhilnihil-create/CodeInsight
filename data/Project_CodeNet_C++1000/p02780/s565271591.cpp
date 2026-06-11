#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int N, K, m = 0, S = 0;
  cin >> N >> K;
  vector<int> v(N);
  REP(i, N) {
    cin >> v[i];
  }
  REP(i, K) {
    S += v[i];
  }
  m = S;
  REP(i, N - K) {
    S -= v[i];
    S += v[K + i];
    if (S > m) m = S;
  }
  cout << fixed << setprecision(8) << (double)(m + K) / 2 << endl;
}
