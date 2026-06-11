#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N + 1);
  ll s = 0;
  for (ll i = 0; i <= N; ++i) {
    cin >> A.at(i);
    s += A.at(i);
  }
  ll cnt = 1;
  ll node = 1;
  ll ans = 0;
  for (ll i = 0; i <= N; ++i) {
    ans += node;
    if (node >= A.at(i)) {
      ll temp = min(s - cnt, node - A.at(i));
      cnt += temp;
      node = (node - A.at(i)) + temp;
    }
    else {
      cout << -1 << "\n";
      return 0;
    }
  }
  cout << ans << "\n";
}
