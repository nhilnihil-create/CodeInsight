#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
ll x[100003], l[100003];
pair<ll,ll> itv[100003];
int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> x[i] >> l[i];
  rep(i,n) itv[i] = make_pair(x[i]+l[i],x[i]-l[i]);
  sort(itv, itv+n);
  int ans = 0;
  ll en = -INF;
  rep(i,n) {
    if (en <= itv[i].second) {
      ans++; en = itv[i].first;
      }
  }
  cout << ans << endl;
    return 0;
}