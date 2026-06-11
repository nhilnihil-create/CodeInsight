#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, d, a;
  cin >> n >> d >> a;
  vector<pll> monster(n);
  for (int i = 0; i < n; i++) cin >> monster[i].first >> monster[i].second;
  sort(monster.begin(), monster.end());

  vector<int> effindex(n);
  //[l, r)の区間で
  int r = 1;
  for (int l = 0; l < n; l++) {
    if (r == n) effindex[l] = n;
    else {
      while((monster[r-1].first - monster[l].first <= 2*d) && (r <= n)) r++;
      effindex[l] = r-1;
    }
  }
  //for (int i = 0; i < n; i++) cout << effindex[i] << " ";
  //cout << endl;

  vector<ll> sublist(n+1);
  ll sub = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sub += sublist[i];
    //cout << i << " " << sub << endl;
    ll cnt = (monster[i].second - sub * a <= 0) ? 0 :((monster[i].second - sub * a - 1) / a) + 1;
    ans += cnt;
    sub += cnt;
    sublist[effindex[i]] -= cnt;
  }
  cout << ans << endl;
}
