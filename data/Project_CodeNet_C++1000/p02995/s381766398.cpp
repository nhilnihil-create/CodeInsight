#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (b > a)
    return gcd(b, a);
  if (b == 0)
    return a;
  return gcd(b, (a % b));
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll ab = lcm(c, d);
  ll total = b-a+1;
  a--;
  ll ans = total - ((b/c+b/d-b/ab)-(a/c+a/d-a/ab));
  cout << ans << endl;
}
