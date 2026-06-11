#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll a, v;
  cin >> a >> v;
  ll b, w;
  cin >> b >> w;
  ll t;
  cin >> t;
  ll d = abs(a - b);
  ll d2 = (v - w) * t;
  puts(d <= d2 ? "YES" : "NO");
  return 0;
}
