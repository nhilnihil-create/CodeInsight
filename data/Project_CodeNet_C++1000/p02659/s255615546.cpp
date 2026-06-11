

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
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


int main() {
  ll A;
  double B;
  cin >> A >> B;
  ll A2 = A;
  ll B2 = B*100 + 0.001;
  ll result = A2 * B2 / 100;
  print(result);
}