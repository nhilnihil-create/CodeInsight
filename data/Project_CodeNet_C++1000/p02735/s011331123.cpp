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

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll dp[110][110];

int main() {
  fill(dp[0], dp[109], INF);

  // std::cout << std::fixed << std::setprecision(10);
  ll H, W;
  scanf("%lld %lld", &H, &W);

  vector<string> walls;
  for (ll h = 0; h < H; h++) {
    string s;
    cin >> s;
    walls.emplace_back(s);
  }

  dp[0][0] = (walls[0][0] == '.' ? 0 : 1);

  for (ll x = 0; x < W; x++) {
    for (ll y = 0; y < H; y++) {
      char c = walls[y][x];

      if (x < W - 1) {
        char right = walls[y][x + 1];
        ll next_value = dp[y][x];
        if (c == '.' && right == '#') {
          next_value += 1;
        }
        dp[y][x + 1] = min(dp[y][x + 1], next_value);
      }
      if (y < H - 1) {
        char down = walls[y + 1][x];
        ll next_value = dp[y][x];
        if (c == '.' && down == '#') {
          next_value += 1;
        }
        dp[y + 1][x] = min(dp[y + 1][x], next_value);
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
  // cout << dp[0][1] << endl;
}
