#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MAX = 1000000000;

int main() {
  ll s;
  cin >> s;
  vector<ll> x(3), y(3);

  x[0] = 0, y[0] = 0;
  x[1] = MAX;
  x[2] = 1;
  y[2] = ceil((double)s / MAX);
  y[1] = x[1] * y[2] - s;

  rep(i, 3) printf("%d %d%c", x[i], y[i], (i == 2 ? '\n' : ' '));

  return 0;
}
