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
  Cin(int, n);
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];
  Cin(string, x);

  int ans = 0;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    if (!ok) {
      if (s[i] == x) ok = true;
    } else
      ans += t[i];
  }

  cout << ans << endl;
}