#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N, M;
  scanf("%lld %lld", &N, &M);

  vector<ll> list[100005];

  for (ll i = 0; i < N; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    list[a].emplace_back(b);
  }

  priority_queue<ll, vector<ll>, less<ll>> q;

  ll ans = 0;
  for (ll i = 1; i <= M; i++) {
    for (ll j = 0; j < list[i].size(); j++) {
      q.push(list[i][j]);
    }
    if (q.size() > 0) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}
