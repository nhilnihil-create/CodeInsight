#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<ll>;
using P = pair<int,int>;
const int INF = 1e9+7;

int main() {
  int n;
  cin >> n;
  vec a(n+1), l(n+1), u(n+1), b(n+1);
  rep (i,n+1) {
    cin >> a[i];
  }

  l[n] = a[n];
  u[n] = a[n];
  for (int i = n-1; i >= 0; i--) {
    l[i] = (l[i+1] + 1) / 2 + a[i];
    u[i] = u[i+1] + a[i];
  }

  if (1 < l[0] || 1 > u[0]) {
    cout << -1 << endl;
    return 0;
  }

  ll sum = 1;
  b[0] = 1-a[0];
  for (int i = 1; i < n+1; i++) {
    b[i] = min(b[i-1]*2, u[i]) - a[i];
    if (a[i] + b[i] < l[i]) {
      cout << -1 << endl;
      return 0;
    }
    sum += a[i] + b[i];
    // cout << l[i] << " " << u[i] << " " << b[i] << endl;
  }

  cout << sum << endl;

  return 0;
}
