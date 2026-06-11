#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s;
  cin >> s;
  int ans = 0, l = 0, r = s.length() - 1;
  while (l < r)
  {
    if (s[l] != s[r])
      ans++;
    l++;
    r--;
  }
  cout << ans << endl;
  return 0;
}