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
  ll s;
  cin >> s;
  ll x1 = 0;
  ll y1 = 0;
  ll x2 = 1000000000;
  ll y2 = 1;
  ll y3 = s/1000000000 + 1;
  if (s % 1000000000 == 0) {
    y3--;
  }
  ll x3 = 1000000000*y3 - s;
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << ' ' << '\n';
}
