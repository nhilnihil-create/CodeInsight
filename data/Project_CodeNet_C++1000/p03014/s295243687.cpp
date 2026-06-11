#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll H, W;
vector<vector<ll>> h_sum, w_sum;
void init(vector<vector<char>>& maze)
{
  for (ll i = 1; i <= H + 1; ++i) {
    ll l = 1, cnt = 0;
    for (ll j = 1; j <= W + 1; ++j) {
      if (maze.at(i).at(j) == '#') {
        for (ll k = l; k < j; ++k) {
          w_sum.at(i).at(k) = cnt;
        }
        cnt = 0;
        l = j + 1;
      }
      else {
        cnt += 1;
      }
    }
  }
  for (ll i = 1; i <= W + 1; ++i) {
    ll l = 1, cnt = 0;
    for (ll j = 1; j <= H + 1; ++j) {
      if (maze.at(j).at(i) == '#') {
        for (ll k = l; k < j; ++k) {
          h_sum.at(k).at(i) = cnt;
        }
        cnt = 0;
        l = j + 1;
      }
      else {
        cnt += 1;
      }
    }
  }
}

int main()
{
  cin >> H >> W;
  h_sum = vector<vector<ll>>(H + 2, vector<ll>(W + 2));
  w_sum = vector<vector<ll>>(H + 2, vector<ll>(W + 2));
  vector<vector<char>> maze(H + 2, vector<char>(W + 2, '#'));
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cin >> maze.at(i + 1).at(j + 1);
    }
  }
  init(maze);
  ll ans = 0;
  for (ll i = 1; i <= H; ++i) {
    for (ll j = 1; j <= W; ++j) {
      ans = max(ans, h_sum.at(i).at(j) + w_sum.at(i).at(j) - 1);
    }
  }
  cout << ans << "\n";
}
