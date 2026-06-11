// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

ll c, d, cd;

// n - (dの倍数の数 + cの倍数の数 - lcm(d, c)の倍数の数)
ll f(ll n) {
  ll dn = n/d;
  ll cn = n/c;
  ll cdn = n/cd;
  return n - (dn + cn - cdn);
}

int main() {
  ll a, b; cin >> a >> b >> c >> d;
  cd = lcm(d, c);
  cout << f(b) - f(a-1) << endl;
  return 0;
}
