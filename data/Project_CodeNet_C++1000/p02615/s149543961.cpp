#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;

  vector<ll> a(n);

  priority_queue<ll, vector<ll>, less<ll>> que;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      que.push(a[i]);
    } else {
      que.push(a[i]);
      que.push(a[i]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
}