#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int H, W, K;
  cin >> H >> W >> K;
  string grid[H];
  for (int i = 0; i < H; i++)
    cin >> grid[i];

  int choices = 0;
  for (int mask1 = 0; mask1 < 1 << H; mask1++) {
    for (int mask2 = 0; mask2 < 1 << W; mask2++) {
      int black = 0;
      for (int i = 0; i < H; i++) {
        if (mask1 & (1 << i))
          continue;
        for (int j = 0; j < W; j++) {
          if (mask2 & (1 << j))
            continue;
          if (grid[i][j] == '#')
            black++;
        }
      }
      if (black == K)
        choices++;
    }
  }

  cout << choices;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  cout << nl;
  // }

  return 0;
}