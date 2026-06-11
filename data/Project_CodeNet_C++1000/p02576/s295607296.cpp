#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, X, T;
  cin >> N >> X >> T;
  int ans = 0, cur = 0;
  while (cur < N) {
    ans += T;
    cur += X;
  }
  cout << ans << nl;
  return 0;
}
