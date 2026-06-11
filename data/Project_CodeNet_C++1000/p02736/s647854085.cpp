#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ff(i, a, b) for(int i = (a); (i <= (b)); ++i)
#define FF(i, a, b) for(int i = (a); (i >= (b)); --i)
#define sz(a) (int) a.size()
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define lwb lower_bound
#define upb upper_bound

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  ff(i, 0, n - 1) a[i] = s[i] - '1';
  bool has1 = false;
  ff(i, 0, n - 1) {
    if (a[i] == 1) has1 = true;
  }
  if (!has1) {
    ff(i, 0, n - 1) a[i] /= 2;
  }
  int ans = 0;
  ff(i, 0, n - 1) {
    int j = (n - 1) - i;
    if ((i ^ j) == (i + j)) {
      ans += a[i]; ans %= 2;
    }
  }
  if (!has1) ans *= 2;
  cout << ans << '\n';
}