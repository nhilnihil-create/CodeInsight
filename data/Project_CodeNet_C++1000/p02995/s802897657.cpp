#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll x, ll y) {
  if (x%y==0) return y;
  return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
  ll t = x / gcd(x, y);
  return t * y;
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  --A;
  ll ans = (B - B/C - B/D + B/lcm(C,D)) - (A - A/C - A/D + A/lcm(C, D));
  cout << ans << endl;
  return 0;
}