#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N) {
    cin >> H[i];
  }
  int tmp = 0, result = 0;
  REP(i, N-1) {
    if (H[i] >= H[i+1]) {
      tmp++;
    } else {
      if (tmp > result) {
        result = tmp;
      }
      tmp = 0;
    }
  }
  if (tmp > result) {
    result = tmp;
  }
  cout << result << endl;
  return 0;
}
