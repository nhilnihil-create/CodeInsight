#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define cn cout << '\n'
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

ll gcd(ll x, ll y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
  ll t = x / gcd(x, y);
  return t * y;
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  --a;
  ll k = (b - b / c - b / d + b / lcm(c, d)) - (a - a / c - a / d + a / lcm(c, d));
  cout << k << endl;
  return 0;
}
