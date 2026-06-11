#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += ((ll)i * (i + 1)) / 2;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap (u, v);
    ans -= ((ll)u * (n - v + 1));
  }

  cout << ans << '\n';
}
