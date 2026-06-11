#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 1)
  {
    cout << "No" << endl;
  }
  else
  {
    int count = 0;
    for (int i = 0; i < n / 2; i++)
    {
      if (s[i] == s[i + (n / 2)])
      {
        count++;
      }
    }
    if (count == n / 2)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
