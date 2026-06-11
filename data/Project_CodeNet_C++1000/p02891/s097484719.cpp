#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  int c = 0, first = 0;
  ll one_cycle = 0, ans = 0;
  rep(i, 1, n) {
    if (s[i - 1] == s[i])
      c++;
    else {
      if (one_cycle == 0)
        first = c;
      one_cycle += (c + 1) / 2;
      c = 0;
    }
  }

  if (n & 1 && c == n - 1) {
    ll t = n / 2;
    ll eve = k / 2;
    ll odd = k - eve;
    ans = t * odd + (t + 1) * eve;
    cout << ans << endl;
    return 0;
  }

  one_cycle += (c + 1) / 2;
  ans = one_cycle * k;

  if (first != 0 && first % 2 == 0 && c % 2 == 0 && s[0] == s[n - 1])
    ans += k - 1;
  cout << ans << endl;
}
