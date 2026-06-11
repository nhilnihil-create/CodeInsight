#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  vector<bool>dp(n+1, false);
  dp[0] = true;
  
  for(int i = 100; i <= 105; i++)
  {
    for(int j = 0; j + i <= n; j++)
    {
      if(dp[j]) dp[j+i] = true;
    }
  }
  if(dp[n]) cout << 1 << endl;
  else cout << 0 << endl;
  
  return 0;
}