#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  string S;
  cin >> S;
  vector<int> R(N + 1, 0), G(N + 1, 0), B(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    if (S[i] == 'R')
      R[i + 1]++;
    else if (S[i] == 'G')
      G[i + 1]++;
    else
      B[i + 1]++;
    R[i + 1] += R[i];
    G[i + 1] += G[i];
    B[i + 1] += B[i];
  }
  for (int i = 0; i < N - 2; i++)
  {
    for (int k = i + 2; k < N; k++)
    {
      if (S[i] == S[k])
        continue;
      int j = (k + i) / 2;
      if (S[i] != 'R' && S[k] != 'R')
      {
        ans += R[k] - R[i];
        if (j - i == k - j && S[j] == 'R')
        {
          ans--;
        }
      }
      else if (S[i] != 'G' && S[k] != 'G')
      {
        ans += G[k] - G[i];
        if (j - i == k - j && S[j] == 'G')
        {
          ans--;
        }
      }
      else
      {
        ans += B[k] - B[i];
        if (j - i == k - j && S[j] == 'B')
        {
          ans--;
        }
      }
    }
  }
  cout << ans << endl;
}