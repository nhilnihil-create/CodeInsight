#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  vector<int> left, right;
  left.emplace_back(-(1 << 28));
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') {
      left.emplace_back(i);
      i += C;
    }
  }
  right.emplace_back(1 << 28);
  for (int i = N - 1; i > -1; i--) {
    if (S[i] == 'o') {
      right.emplace_back(i);
      i -= C;
    }
  }
  reverse(right.begin(), right.end());
  for (int i = 0; i < N; i++) {
    int x = lower_bound(left.begin(), left.end(), i) - left.begin() - 1;
    int y = lower_bound(right.begin(), right.end(), max(left[x] + C, i + 1)) -
            right.begin();
    y = (int)right.size() - 1 - y;
    if (x + y < K) cout << i + 1 << '\n';
  }
  return 0;
}
