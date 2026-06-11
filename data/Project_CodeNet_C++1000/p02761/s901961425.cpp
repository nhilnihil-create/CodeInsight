#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  vector<int>s(N, -1);
  for (int i = 0; i < M; i ++) {
    int k, c;
    cin >> k >> c;
    if (s[N - k] != -1 && s[N - k] != c) {
      cout << -1 << endl;
      return 0;
    }
    s[N - k] = c;
  }
  if (s[N - 1] == -1) {
    if (N > 1) s[N - 1] = 1;
    else s[N - 1] = 0;
  }
  if (s[N - 1] == 0) {
    cout << (N == 1 ? 0 : -1) << endl;
    return 0;
  }
  for (int i = 0; i < N - 1; i ++) {
    if (s[i] == -1) s[i] = 0;
  }
  int ans = 0;
  for (int i = N - 1; i >= 0; i --) {
    ans *= 10;
    ans += s[i];
  }
  cout << ans << endl;
}
