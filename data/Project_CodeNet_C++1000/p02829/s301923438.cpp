#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll a, b;
  cin >> a >> b;
  rep(i, 3) {
    if (a != i + 1 && b != i + 1) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
