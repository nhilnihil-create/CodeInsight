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

  ll n, m;
  cin >> n >> m;
  vector<pll> works(n);
  for (int i = 0; i < n; i++) cin >> works[i].first >> works[i].second;
  sort(works.begin(), works.end());
  //reverse(works.begin(), works.end());

  priority_queue<ll, vector<ll>> que;
  ll ans = 0;
  int index = 0;
  for (int i = m-1; i >= 0; i--) {
    while ((index < n) && (works[index].first <= m-i)) {
      que.push(works[index].second);
      index++;
    }

    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << endl;
}
