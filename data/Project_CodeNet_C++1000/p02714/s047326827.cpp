#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 余事象を引く
  int N;
  cin >> N;
  string S;
  cin >> S;
  int r = 0, g = 0, b = 0;
  for (char s : S) {
    if (s == 'R') r++;
    if (s == 'G') g++;
    if (s == 'B') b++;
  }
  ll ans = (ll)r * g * b;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (S[i] == S[j]) continue;
      int k = j + (j-i);
      if (k >= N) continue;
      if (S[i] != S[k] && S[j] != S[k]) ans--;
    }
  }
  cout << ans << '\n';
  return 0;
}
