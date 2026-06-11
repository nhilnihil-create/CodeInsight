#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n) {
    if (s[i] == s[i + 1]) continue;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}