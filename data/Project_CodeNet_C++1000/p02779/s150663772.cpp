#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
