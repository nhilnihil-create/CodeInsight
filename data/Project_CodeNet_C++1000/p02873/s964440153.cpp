#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int64_t N = S.size(), ans = 0;
  vector<pair<int64_t, char>> v;
  v.emplace_back(1, S.at(0));
  for (int64_t i = 1; i < N; i++)
  {
    if (S.at(i) == S.at(i - 1))
    {
      v.at(v.size() - 1).first++;
    }
    else
    {
      v.emplace_back(1, S.at(i));
    }
  }
  for (int64_t i = 0; i < (int64_t)(v.size() - 1); i++)
  {
    if (v[i].second == '<' && v[i + 1].second == '>')
    {
      if (v[i].first >= v[i + 1].first)
      {
        v[i + 1].first--;
      }
      else
      {
        v[i].first--;
      }
    }
  }
  for (int64_t i = 0; i < (int64_t)(v.size()); i++)
  {
    ans += v[i].first * (v[i].first + 1) / 2;
  }
  cout << ans << endl;
}
