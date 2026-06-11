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
  ll T1, T2;
  scanf("%lld %lld", &T1, &T2);

  ll A1, A2;
  scanf("%lld %lld", &A1, &A2);

  ll B1, B2;
  scanf("%lld %lld", &B1, &B2);

  ll dist_a1 = A1 * T1;
  ll dist_b1 = B1 * T1;

  ll dist_a2 = A2 * T2;
  ll dist_b2 = B2 * T2;

  // cout << (dist_a1 + dist_a2) << endl;
  // cout << (dist_b1 + dist_b2) << endl;

  if (dist_a1 + dist_a2 == dist_b1 + dist_b2) {
    cout << "infinity" << endl;
    return 0;
  }

  ll dist_diff1;
  ll dist_diff2;
  ll next_init_diff;
  if (dist_a1 > dist_b1) {
    dist_diff1 = dist_a1 - dist_b1;
    dist_diff2 = dist_b2 - dist_a2;
    next_init_diff = dist_diff2 - dist_diff1;
  }
  if (dist_a1 < dist_b1) {
    dist_diff1 = dist_b1 - dist_a1;
    dist_diff2 = dist_a2 - dist_b2;
    next_init_diff = dist_diff2 - dist_diff1;
  }

  if (dist_diff2 <= dist_diff1) {
    cout << 0 << endl;
    return 0;
  }

  // cout << "dist_diff1:" << dist_diff1 << endl;
  // cout << "dist_diff2:" << dist_diff2 << endl;
  // cout << "next_init_diff:" << next_init_diff << endl;

  // if (next_init_diff > dist_diff1) {
  //   cout << 1 << endl;
  //   return 0;
  // }

  ll ans = (dist_diff1 - 1) / next_init_diff + 1;
  ans *= 2;
  if (dist_diff1 % next_init_diff != 0) {
    ans--;
  }

  cout << ans << endl;
}
