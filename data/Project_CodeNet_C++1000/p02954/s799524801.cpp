#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  vector<int> A(N, 0);
  for (int i = 0; i < 2; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if (S[j] == 'R')
      {
        cnt++;
      }
      else
      {
        A[j] += cnt / 2;
        A[j - 1] += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    reverse(A.begin(), A.end());
    reverse(S.begin(), S.end());
    for (int j = 0; j < N; j++)
    {
      S[j] = (S[j] == 'R' ? 'L' : 'R');
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (i)
      cout << ' ';
    cout << A[i];
  }
  cout << endl;
}