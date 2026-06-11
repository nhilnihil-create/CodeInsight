#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x[200005];
ll y[200005];
int main() {
  ll n, d, ans = 0;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] * x[i] + y[i] * y[i] <= d * d) {
      ans++;
    }
  }
  cout << ans << endl;
}
