#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int h, w, d[110][110];
bool g[110][110];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> h >> w;
  char c;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> c, g[i][j] = c == '#', d[i][j] = h + w + 10;
  d[0][0] = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (d[i][j] + (g[i][j] != g[i][j + 1]) < d[i][j + 1])
        d[i][j + 1] = d[i][j] + (g[i][j] != g[i][j + 1]);
      d[i + 1][j] = d[i][j] + (g[i][j] != g[i + 1][j]);
    }
  cout << (d[h - 1][w - 1] + g[0][0] + 1) / 2 << "\n";
}
