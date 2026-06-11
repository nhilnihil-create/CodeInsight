#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max(a - k, 0LL) << " " << max(b - max(k - a, 0LL), 0LL) << endl;
  return 0;
}
