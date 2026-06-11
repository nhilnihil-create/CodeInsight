#pragma region Macros
#include <bits/stdc++.h>
#define int long long
using ll = long long;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(ll i = ll(a); i < ll(b+a); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#pragma endregion

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int s,w; cin >> s >> w;

  if (s>w)
    cout << "safe" << endl;
  else
    cout << "unsafe" << endl;

  return 0;
}
