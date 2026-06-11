#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;

  int ans = T.size();

  for (int i = 0; i <= S.size() - T.size(); i++)
  {
    int tmp = 0;
    for (int j = 0; j < T.size(); j++)
    {
      if (S.at(i + j) != T.at(j))
      {
        tmp++;
      }
    }
    ans = min(tmp, ans);
  }

  cout << ans << endl;
}
