#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> v;
  int crt = n;
  while (true)
  {
    if (crt <= m)
    {
      v.push_back(crt);
      break;
    }
    for (int i = m; i > 0; i--)
    {
      if (s[crt-i] == '0')
      {
        v.push_back(i);
        crt -= i;
        break;
      }
      if (i == 1)
      {
        puts("-1");
        return 0;
      }
    }
  }
  for (int i = v.size() - 1; i >= 0; i--)
    printf("%d%c", v[i], i==0?'\n':' ');
  return 0;
}