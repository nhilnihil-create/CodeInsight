#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,k,r,s,p;
  cin >> n >> k >> r >> s >> p;

  string t;
  cin >> t;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if(i - k >= 0 && t[i] == t[i - k]) {
      t[i] = '?';
      continue;
    }

    if(t[i] == 'r') ans += p;
    if(t[i] == 's') ans += r;
    if(t[i] == 'p') ans += s;
  }

  cout << ans << '\n';
}