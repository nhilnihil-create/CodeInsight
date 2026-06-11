#include <bits/stdc++.h>
using namespace std;

int main()
{
  string k;
  long long int n;
  vector<long long int> p;
  cin >> k;
  cin >> n;

  long long int t = 1;
  for (int i = 1; i < k.length(); i++)
  {
    if (k[i - 1] == k[i])
    {
      t++;
    }
    else
    {
      p.push_back(t);
      t = 1;
    }
  }
  p.push_back(t);

  long long int res = 0;
  if (k[0] == k[k.length() - 1])
  {
    if (p.size() == 1)
    {
      res += (p[0] * n) / 2;
    }
    else
    {
      res += p[0] / 2;
      for (int i = 1; i < p.size() - 1; i++)
      {
        res += (p[i] / 2) * n;
      }
      res += ((p[0] + p[p.size() - 1]) / 2) * (n - 1);
      res += p[p.size() - 1] / 2;
    }
  }
  else
  {
    for (int i = 0; i < p.size(); i++)
    {
      res += (p[i] / 2) * n;
    }
  }

  cout << res << endl;

  return 0;
}
