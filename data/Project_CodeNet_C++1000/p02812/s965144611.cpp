#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m; cin >> m;
  string s; cin >> s;
  int n = s.length(); int ans = 0;
  for(int i = 0; i <= n-3; ++i)
  {
    ans += (s.substr(i, 3) == "ABC");
  }
  cout << ans;
  return 0;
}