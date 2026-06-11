#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
string s;

int main()
{
  cin >> s;

  int n = s.length();

  rep(i, n)
  {
    if (s[i] == '?')
    {
      s[i] = 'D';
    }
  }

  cout << s << endl;
}
