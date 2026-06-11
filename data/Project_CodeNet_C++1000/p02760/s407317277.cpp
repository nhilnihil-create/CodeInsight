#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> a[i][j];
    }
  }

  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  vector<vector<int>> bingo(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      bingo[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        if (a[i][j] == b[k])
        {
          bingo[i][j] = 1;
        }
      }
    }
  }
  string ans = "No";
  for (int i = 0; i < 3; i++)
  {
    if (bingo[i][0] && bingo[i][1] && bingo[i][2])
    {
      ans = "Yes";
    }
    if (bingo[0][i] && bingo[1][i] && bingo[2][i])
    {
      ans = "Yes";
    }
  }
  if (bingo[0][2] && bingo[1][1] && bingo[2][0])
  {
    ans = "Yes";
  }
  if (bingo[0][0] && bingo[1][1] && bingo[2][2])
  {
    ans = "Yes";
  }
  cout << ans << endl;
}
