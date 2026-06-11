#include <bits/stdc++.h>
using namespace std;

vector<int> Zalgorithm(const string &s)
{
  int n = s.size();
  vector<int> res(n);
  res[0] = n;
  int i = 1, j = 0;
  while (i < n)
  {
    while (i + j < n && s[j] == s[i + j])
      ++j;
    res[i] = j;
    if (j == 0)
    {
      ++i;
      continue;
    }

    int k = 1;
    while (i + k < n && res[k] < j - k)
    {
      res[i + k] = res[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return res;
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s;
  cin >> s;

  int res = 0;
  for (int i = 0; i < N; i++)
  {
    string t = s.substr(i);
    auto lcp = Zalgorithm(t);

    for (int j = 0; j < t.size(); j++)
    {
      int l = min(lcp[j], j);
      res = max(res, l);
    }
  }
  cout << res << endl;
  return 0;
}
//参考
