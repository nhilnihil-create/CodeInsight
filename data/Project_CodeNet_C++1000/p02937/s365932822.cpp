#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  vector<vector<int>> V(30);
  for (int i = 0; i < S.size(); i++)
  {
    int ic = S.at(i) - 'a';
    V.at(ic).push_back(i);
  }
  int64_t ans = 0, pos = -1;
  for (int i = 0; i < T.size(); i++)
  {
    int a = T.at(i) - 'a';
    if (V.at(a).size() == 0)
    {
      cout << -1 << endl;
      return 0;
    }
    auto itr = upper_bound(V.at(a).begin(), V.at(a).end(), pos);
    if (itr == V.at(a).end())
    {
      ans += (S.size() - 1 - pos) + (V.at(a)[0] + 1);
      pos = V.at(a)[0];
    }
    else
    {
      ans += *itr - pos;
      pos = *itr;
    }
  }
  cout << ans << endl;
}
