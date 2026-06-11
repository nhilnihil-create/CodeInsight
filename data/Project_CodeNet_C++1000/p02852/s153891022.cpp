#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<int> steps(N + 1, INF);
  steps.at(N) = 0;
  vector<bool> checked(N + 1, false);
  checked.at(N) = true;
  for (int i = N; i > 0; i--)
  {
    if (S[i] == '1')
    {
      continue;
    }
    for (int j = max(0, i - M); j <= i; j++)
    {
      if (checked.at(j))
      {
        break;
      }
      checked.at(j) = true;
      if (S[j] == '1')
      {
        continue;
      }
      steps.at(j) = steps.at(i) + 1;
    }
  }
  if (steps.at(0) >= INF)
  {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 1; j <= M && i + j <= N; j++)
    {
      if (steps.at(i + j) == steps.at(i) - 1)
      {
        ans.push_back(j);
        i += j - 1;
        break;
      }
    }
  }
  for (int i = 0; i < (int)ans.size(); i++)
  {
    if (i)
      cout << ' ';
    cout << ans.at(i);
  }
  cout << endl;
}
