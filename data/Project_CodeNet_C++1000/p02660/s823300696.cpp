#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n;
  cin >> n;

  int x = n;
  int answer = 0;
  for (int d = 2; d * d <= n; d++) {
    int cnt = 0;
    while(x % d == 0) {
      cnt++;
      x /= d;
    }
    int sub = 1;
    while(true) {
      cnt -= sub;
      if(cnt < 0) break;
      answer++;
      sub++;
    }
  }
  if(x > 1) answer++;
  cout << answer << '\n';
}