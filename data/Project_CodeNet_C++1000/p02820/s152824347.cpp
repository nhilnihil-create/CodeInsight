#include <bits/stdc++.h>
using namespace std;

int R, S, P;

int win(char c) {
  int ret = 0;
  if (c == 'r') ret += P;
  if (c == 's') ret += R;
  if (c == 'p') ret += S;
  return ret;
}

int main() {
  int N, K;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i < K) {
      ans += win(T.at(i));
      continue;
    }
    if (T.at(i) == T.at(i - K)) T.at(i) = ' ';
    else ans += win(T.at(i));
  }
  cout << ans << "\n";
}