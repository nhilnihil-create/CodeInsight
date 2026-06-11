#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  if (s.length() % 2 == 1)
    cout << "No\n";
  else
  {
    int f = 0;
    for (int i = 0; i < s.length() - 1; i += 2)
    {
      if (s[i] != 'h' || s[i + 1] != 'i')
      {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}
