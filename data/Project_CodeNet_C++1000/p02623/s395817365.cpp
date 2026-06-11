#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> arui(n+1);
    vector<ll> brui(m+1);
    for (int i = 1; i <= n; i++) {
      ll a;
      cin >> a;
      arui[i] = arui[i-1] + a;
    }
    for (int i = 1; i <= m; i++) {
      ll b;
      cin >> b;
      brui[i] = brui[i-1] + b;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      ll bk = k-arui[i];
      if (bk < 0) break;
      auto iter = upper_bound(brui.begin(), brui.end(), bk);
      int j = iter - brui.begin() - 1;
      ans = max(ans,i+j);
    }
    cout << ans << endl;
    return 0;
}