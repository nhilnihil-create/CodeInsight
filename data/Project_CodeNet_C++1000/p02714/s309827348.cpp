#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, r = 0, b = 0, g = 0;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == 'R')
      r++;
    else if (S[i] == 'G')
      g++;
    else
      b++;
  }
  int64_t ans = r * g * b;
  for (int i = 0; i < N; i++)
  {
    for (int l = 1; l < N; l++)
    {
      int j = i + l, k = i + 2 * l;
      if (k >= N)
      {
        break;
      }
      if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i])
      {
        ans--;
      }
    }
  }
  cout << ans << endl;
}