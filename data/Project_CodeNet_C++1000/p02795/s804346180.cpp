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
  ll H;
  scanf("%lld", &H);

  ll W;
  scanf("%lld", &W);

  ll N;
  scanf("%lld", &N);

  ll b = max(H, W);
  ll s = min(H, W);

  ll count = 0;
  ll ans = 0;
  for (ll i = 0; i < s; i++) {
    count += b;
    ans++;
    if (count >= N) {
      break;
    }
  }
  cout << ans << endl;
}
