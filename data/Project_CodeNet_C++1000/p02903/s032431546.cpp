#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  vector<vector<ll>> ans(H, vector<ll>(W, 1));
  for (ll i = 0; i < B; ++i) {
    for (ll j = 0; j < W; ++j) {
      ans.at(i).at(j) = (ans.at(i).at(j) + 1) % 2;
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < A; ++j) {
      ans.at(i).at(j) = (ans.at(i).at(j) + 1) % 2;
    }
  }
  for (ll i = 0; i < H; ++i) {
    for (ll j = 0; j < W; ++j) {
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
}
