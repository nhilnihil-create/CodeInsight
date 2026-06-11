#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > pos (n + 1);
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    pos[a] = i;
  }

  ll ans = 0;
  multiset < int > s;
  s.insert (0); s.insert (0); s.insert (n + 1); s.insert (n + 1);
  for (int i = n; i >= 1; i--) {
    auto it = s.upper_bound (pos[i]);
    int y = *it, q = *(++it);
    --it;
    int x = *(--it), p = *(--it);
    s.insert (pos[i]);

    ans += (ll)(x - p) * (y - pos[i]) * i;
    ans += (ll)(pos[i] - x) * (q - y) * i;
  }

  cout << ans << '\n';
}
