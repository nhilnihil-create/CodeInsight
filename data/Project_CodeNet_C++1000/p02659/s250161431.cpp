#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  ll int_b = b*100+0.1; // 切り捨てで壊れないよに
  a *= int_b;
  a /= 100;
  printf("%lld\n", a);
  return 0;
}