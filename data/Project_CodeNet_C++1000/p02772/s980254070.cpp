#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, a;
  cin >> n;
  bool flag = true;
  rep(i, n) {
    cin >> a;
    if (a % 2 == 0) flag &= (a % 3 == 0 || a % 5 == 0);
  }
  cout << (flag ? "APPROVED" : "DENIED") << endl;
  return 0;
}
