#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ld a, b, x;
  cin >> a >> b >> x;
  ld space = a*a*b - x;
  if (2*space/a/a <= b) {
    cout << fixed << setprecision(7) << 90 - atan((a*a*a)/2/space) * 180/Pi  << '\n';
  }
  else {
    cout << fixed << setprecision(7) << 90 - atan(2*x/a/b/b) * 180/Pi  << '\n';
  }
}