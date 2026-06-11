#include <bits/stdc++.h>
#define sz(arr) (int)(arr).size()
#define rng(arr) arr.begin(), arr.end()
#define show(x) cout << #x << " = " << x << endl;

using namespace std;
typedef long long int ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  Main();
  return 0;
}

void Main() {
  Cin(int, m, d);

  auto d1 = [](int d) {
    string s = to_string(d);
    if (sz(s) != 2) return 0;
    return s[1] - '0';
  };
  auto d10 = [](int d) {
    string s = to_string(d);
    if (sz(s) != 2) return 0;
    return s[0] - '0';
  };

  int ans = 0;
  for (int i = 2; i <= m; ++i) {
    for (int j = 22; j <= d; ++j) {
      if (!(d1(j) >= 2 && d10(j) >= 2)) continue;
      if (i == d1(j) * d10(j)) ans++;
    }
  }

  cout << ans << endl;
}