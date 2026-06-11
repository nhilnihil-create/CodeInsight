#include <bits/stdc++.h>
using namespace std;
int dp[35][100005];

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    if (S[i] == 'R')
      dp[0][i] = i + 1;
    else
      dp[0][i] = i - 1;
  }
  for (int i = 0; i < 31; i++)
  {
    for (int j = 0; j < N; j++)
    {
      dp[i + 1][j] = dp[i][dp[i][j]];
    }
  }
  for (int i = 0; i < N; i++)
  {
    A[dp[30][i]]++;
  }
  for (int i = 0; i < N; i++)
  {
    if (i)
      cout << ' ';
    cout << A[i];
  }
  cout << endl;
}