#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  ll r, g, b;
  r = g = b = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'R')
    {
      r++;
    }
    else if (s[i] == 'G')
    {
      g++;
    }
    else if (s[i] == 'B')
    {
      b++;
    }
  }

  ll ng = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (s[i] == s[j])
        continue;
      int k = j * 2 - i;
      if (k >= n || s[k] == s[i] || s[k] == s[j])
        continue;

      ng++;
    }
  }
  ll rgb = r * g * b;
  cout << rgb - ng << endl;
}
