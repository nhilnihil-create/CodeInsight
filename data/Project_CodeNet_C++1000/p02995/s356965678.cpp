#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll s1 = a/c;
  ll s2 = b/c;
  ll t1 = a/d;
  ll t2 = b/d;
  ll u1 = a/lcm(c,d);
  ll u2 = b/lcm(c,d);
  cout <<b-a - ((s2-s1)+(t2-t1)-(u2-u1)) << '\n';
}