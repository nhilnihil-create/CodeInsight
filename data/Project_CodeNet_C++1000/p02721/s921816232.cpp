#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K, C;
  cin >> N >> K >> C;

  string S;
  cin >> S;

  vector<int> ldp(N, 0);
  for (int i = 0; i < N; i++) {
    if (i - C <= 0) {
      ldp[i] = 1;
    } else {
      if (S[i] == 'x') {
        ldp[i] = ldp[i - 1];
      } else {
        ldp[i] = ldp[i - C - 1] + 1;
      }
    }
  }

  vector<int> rdp(N, 0);
  for (int i = N - 1; i >= 0; i--) {
    if (i + C >= N) {
      rdp[i] = 1;
    } else {
      if (S[i] == 'x') {
        rdp[i] = rdp[i + 1];
      } else {
        rdp[i] = rdp[i + C + 1] + 1;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    int l = (i - 1 >= 0 ? ldp[i - 1] : 0);
    int r = (i + 1 <= N - 1 ? rdp[i + 1] : 0);
    if (l + r < K) {
      cout << i + 1 << "\n";
    }
  }

  return 0;
}