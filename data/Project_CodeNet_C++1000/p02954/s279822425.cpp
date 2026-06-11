#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s;
  cin >> s;
  vector<int> ans(s.size(), 0);
  vector<int> c(2, 0);
  c[0] = 1;
  int lastr = 0;
  for (int i=1; i<s.size(); i++)
  {
    if (s[i] == 'R')
    {
      c[i%2]++;
      lastr = i;
    }
    else if (s[i-1] == 'R')
    {
      c[i%2]++;
      ans[i] += c[i%2];
      c[i%2] = 0;
      ans[i-1] += c[i%2^1];
      c[i%2^1] = 0;
    }
    else if (lastr % 2 == i % 2)
      ans[lastr]++;
    else
      ans[lastr+1]++;
  }
  rep(i, s.size())
    if (i < s.size() - 1)
      printf("%d ", ans[i]);
    else
      printf("%d\n", ans[i]);
  return 0;
}