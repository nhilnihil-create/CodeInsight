#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;
const int64_t MAXN = 1e5 + 10;

int main()
{
  string S;
  cin >> S;
  vector<vector<int64_t>> DP(S.size() + 1, vector<int64_t>(13, 0));
  reverse(S.begin(), S.end());
  DP[0][0] = 1;
  int64_t n = 1; // 次の桁のベースの余り数
  for (int i = 0; i < S.size(); i++)
  {
    char c = S[i];
    int64_t r = 0;
    if (c == '?')
    {
      for (int j = 0; j < 13; j++)
      {
        for (int k = 0; k < 10; k++)
        {
          DP[i + 1][(j + k * n) % 13] += DP[i][j];
          DP[i + 1][(j + k * n) % 13] %= MOD;
        }
      }
    }
    else
    {
      int intc = c - '0';
      for (int j = 0; j < 13; j++)
      {
        DP[i + 1][(j + intc * n) % 13] += DP[i][j];
        DP[i + 1][(j + intc * n) % 13] %= MOD;
      }
    }
    n = (n * 10) % 13;
  }
  cout << DP[S.size()][5] << endl;
}
