#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  rep(i, 1000) {
    int num[3] = {i / 100, (i / 10) % 10, i % 10};
    int b = 0;
    rep(j, N) {
      if (S[j] == ('0' + num[b])) b++;
      if (b == 3) break;
    }
    if (b == 3) ans++;
  }

  cout << ans << endl;
  return 0;
}