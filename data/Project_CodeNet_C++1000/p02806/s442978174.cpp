#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i] >> t[i];
  }
  string x;
  cin >> x;
  bool ok = false;
  int rez = 0;
  for (int i = 0; i < n; i++)
  {
    if (ok)
    {
      rez += t[i];
    }
    if (s[i] == x)
    {
      ok = true;
    }
  }
  cout << rez << '\n';
}