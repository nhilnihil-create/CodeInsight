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
  ll H, W, M;
  scanf("%lld %lld %lld", &H, &W, &M);

  vll h_list = vll(300005);
  vll w_list = vll(300005);

  mll points;

  ll h_max = -1;
  ll w_max = -1;
  // vector<l_l> list;
  for (ll i = 0; i < M; i++) {
    ll h, w;
    scanf("%lld %lld", &h, &w);
    // list.emplace_back(make_pair(h, w));

    h_list[h]++;
    w_list[w]++;

    h_max = max(h_max, h_list[h]);
    w_max = max(w_max, w_list[w]);

    points[h + w * 1000000LL] = 1;
  }

  vll y_list;
  vll x_list;

  for (ll i = 0; i < 300005; i++) {
    if (h_list[i] == h_max) {
      y_list.emplace_back(i);
    }
  }
  for (ll i = 0; i < 300005; i++) {
    if (w_list[i] == w_max) {
      x_list.emplace_back(i);
    }
  }

  ll ans = h_max + w_max - 1;

  for (auto y : y_list) {
    for (auto x : x_list) {
      if (!points[y + x * 1000000LL]) {
        cout << ans + 1 << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;
}
