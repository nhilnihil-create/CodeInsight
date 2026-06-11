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
  vector<int> a(n+1,0);
  rep(i,n) cin >> a[i+1];

  vector<int> x(n+1,0);
  for (int i = n; i > 0; i--){
    ll s = 0;
    for (int j = i; j <= n; j += i) s += x[j];
    if (s % 2 != a[i]) x[i]++;
  }

  int ans = 0;
  rep(i,n) ans += x[i+1];
  cout << ans << endl;
  rep(i,n) if (x[i+1] == 1) cout << i+1 << endl;

  return 0;
}
