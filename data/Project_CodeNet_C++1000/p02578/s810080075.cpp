#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  ll ans = 0, last = 0;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    if (a < last) ans += last - a;
    last = max(last, a);
  }
  cout << ans << nl;
  return 0;
}
