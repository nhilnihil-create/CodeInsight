#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t ans = 0;
  string S, prev = "";
  cin >> S;
  for (int i = 0; i < S.size(); i++)
  {
    string sub = to_string(S.at(i));
    if (sub != prev)
    {
      ans++;
      prev = sub;
      continue;
    }
    for (int j = i + 1; j < S.size(); j++)
    {
      sub = sub + S.at(j);
      if (sub != prev)
      {
        ans++;
        prev = sub;
        i = j;
        break;
      }
    }
  }
  cout << ans << endl;
}