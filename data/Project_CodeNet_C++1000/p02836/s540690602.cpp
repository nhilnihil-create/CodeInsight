#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  int n = s.length();
  for (int i = 0; i < n / 2; i++)
  {
    if (s[i] != s[n - 1 - i])
    {
      ans++;
    }
  }
  cout << ans << endl;
}
