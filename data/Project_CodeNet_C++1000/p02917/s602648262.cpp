#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  ll ans = 0;

  vector<ll> list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list.emplace_back(v);
  }

  ans += list[0];
  ans += list[list.size() - 1];

  for (ll i = 0; i < N - 2; i++) {
    ans += min(list[i], list[i + 1]);
  }

  cout << ans << endl;
}
