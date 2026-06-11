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

  ll ans = -1;

  for (ll i = 0; i <= 1000000; i++) {
    ll p = i + (i * 8) / 100;

    if (p == N) {
      ans = i;
      break;
    }
  }

  if (ans == -1) {
    cout << ":(" << endl;
  } else {
    cout << ans << endl;
  }
}
