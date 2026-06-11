#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> x(n,0);
  rep(i,n) x[0] += a[i];
  for(int i = 1; i <= n-2; i += 2) x[0] -= 2*a[i];
  for(int i = 1; i < n; i++) x[i] = 2*a[i-1] - x[i-1];

  rep(i,n) cout << x[i] << endl;
  return 0;
}
