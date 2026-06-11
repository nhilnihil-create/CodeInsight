#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  ll v1 = 0;
  ll v2 = 0;
  ll v3 = 0;

  // vector<ll> list;
  ll ans = 1;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    // list.emplace_back(v);

    ll num = 0;
    if (v1 == v) num++;
    if (v2 == v) num++;
    if (v3 == v) num++;

    if (v1 == v) {
      v1++;
    } else if (v2 == v) {
      v2++;
    } else if (v3 == v) {
      v3++;
    }

    ans = (ans * num) % MOD;
  }
  cout << ans << endl;
}
