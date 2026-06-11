/*input
3 0
3 4 5
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double EPS = 1e-9;

int n, k;
vector<double> a;

bool C(double t) {
  ll res = 0;
  rep(i, n) {
    res += (ll)(ceil(a[i]/t)+EPS)-1;
    if (res > k) return false;
  }
  return true;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  rep(i, n) cin >> a[i];
  double lb = 0, ub = 1e9;
  rep(i, 100) {
    double mid = (lb+ub)/2.0;
    if (C(mid)) ub = mid;
    else lb = mid;
  }
  cout << (ll)(ceil(lb)+EPS) << endl;
}