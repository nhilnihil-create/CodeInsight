#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  long long can_div_c = floor((long double)b / c) - ceil((long double)a / c) + 1;
  long long can_div_d = floor((long double)b / d) - ceil((long double)a / d) + 1;
  long long cd = c * d / __gcd(c, d);
  long long can_div_cd = floor((long double)b / cd) - ceil((long double)a / cd) + 1;

  cout << (b - a + 1) - (can_div_c + can_div_d - can_div_cd) << endl;
  return 0;
}