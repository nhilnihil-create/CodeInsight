#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

bool isok(ll mid, ll temp, ll k, vector<ll>& sumb) {
  return temp + sumb[mid] <= k;
}
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  vector<ll> suma(n, 0), sumb(m, 0);
  partial_sum(a.begin(), a.end(), suma.begin());
  partial_sum(b.begin(), b.end(), sumb.begin());
  suma.insert(suma.begin(), 0);
  sumb.insert(sumb.begin(), 0);

  ll ans = 0;

  for (int i = 0; i < n + 1; i++) {
    ll temp = suma[i];

    ll ok = -1, ng = m + 1, mid;
    while (ng - ok > 1) {
      mid = (ok + ng) / 2;
      if (isok(mid, temp, k, sumb)) {
        ok = mid;
      } else {
        // cout << "a" << endl;
        ng = mid;
      }
    }

    // cout << ok << " " << ng << endl;
    ans = max(ans, ok == -1 ? 0 : ok + i);
  }

  cout << ans << endl;
}