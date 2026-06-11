#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  map<char, int> mp;
  string t;
  cin >> n >> k >> mp['s'] >> mp['p'] >> mp['r'] >> t;
  vector<bool> win(n);
  int ans = 0;
  rep(i, n)
  {
    if (i >= k && t[i] == t[i-k] && win[i-k])
      win[i] = false;
    else
    {
      win[i] = true;
      ans += mp[t[i]];
    }
  }
  cout << ans << endl;
  return 0;
}