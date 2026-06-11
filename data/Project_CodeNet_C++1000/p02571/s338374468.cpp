#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string S, T;
  cin >> S >> T;
  int ans = sz(S);
  for (int i = 0; i + sz(T) <= sz(S); i++) {
    int cnt = 0;
    for (int j = 0; j < sz(T); j++) cnt += S[i + j] != T[j];
    ans = min(ans, cnt);
  }
  cout << ans << nl;
  return 0;
}
