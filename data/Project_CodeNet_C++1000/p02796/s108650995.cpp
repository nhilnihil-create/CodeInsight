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
  ll N;
  scanf("%lld", &N);

  vector<tuple<ll, ll, ll>> list(N);
  for (ll i = 0; i < N; i++) {
    ll x, l;
    scanf("%lld %lld", &x, &l);

    ll c = x + l;

    list[i] = make_tuple(c, x, l);
    // cout << get<0>(list[i]) << endl;
  }
  sort(list.begin(), list.end());

  ll removed = 0;

  ll right = get<1>(list[0]) + get<2>(list[0]);

  for (ll i = 1; i < N; i++) {
    ll x = get<1>(list[i]);
    ll l = get<2>(list[i]);

    if (x - l >= right) {
      right = x + l;
    } else {
      removed++;
    }
  }

  cout << (N - removed) << endl;
}
