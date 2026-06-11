#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
constexpr long long INF = 1LL << 60;
constexpr long long MOD = 998244353;

int n, q, x, y;
string s;
long long a[6060];

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int h;
  cin >> h;
  int w;
  cin >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i)
    cin >> s[i];

  vector<vector<int>> L(h + 5, vector<int>(w + 5));
  vector<vector<int>> R(h + 5, vector<int>(w + 5));
  vector<vector<int>> U(h + 5, vector<int>(w + 5));
  vector<vector<int>> D(h + 5, vector<int>(w + 5));
  for (size_t i = 0; i < h; i++)
  {
    for (size_t j = 0; j < w - 1; j++)

      if (s[i][j] == '.')
        L[i][j + 1] = L[i][j] + 1;

    for (size_t j = w - 1; j > 0; j--)
      if (s[i][j] == '.')
        R[i][j - 1] = R[i][j] + 1;
  }

  for (size_t j = 0; j < w; j++)
  {
    for (size_t i = 0; i < h - 1; i++)
      if (s[i][j] == '.')
        U[i + 1][j] = U[i][j] + 1;

    for (size_t i = h - 1; i > 0; i--)
      if (s[i][j] == '.')
        D[i - 1][j] = D[i][j] + 1;
  }

  int ans = 0;
  for (size_t i = 0; i < h; i++)
  {
    for (size_t j = 0; j < w; j++)
    {
      if (s[i][j] == '.')
        ans = max(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] + 1);
    }
  }
  cout << ans;

  return 0;
}
