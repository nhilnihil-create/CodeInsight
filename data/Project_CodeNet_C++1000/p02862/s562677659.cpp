

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
using namespace std;
using ll = long long;
using lld = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t =  a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int bit_counter(int x) {
  if (x == 0) return 0;
  return bit_counter(x >> 1) + (x&1);
}


int main() {
  ll X, Y;
  cin >> X >> Y;

  ll tx = 2 * X - Y;
  ll ty = 2 * Y - X;

  if (tx%3 != 0 || ty%3 != 0) {
    print(0);
    return 0;
  }

  if (tx < 0 || ty < 0 ) {
    print(0);
    return 0;
  }

  tx /= 3;
  ty /= 3;

  ll result = 1;
  ll bb = tx + ty;
  ll bc = min(tx, ty);
  while(bc > 0) {
    result = (result * bb) % DIV;
    result = (result * modinv(bc, DIV)) % DIV;
    bb--;
    bc--;
  }
  print(result);
}