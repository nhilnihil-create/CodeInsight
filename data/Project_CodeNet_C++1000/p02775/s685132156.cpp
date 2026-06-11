#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 ;
int dp[N][2] ;
int main()
{
  string s ;
  cin >> s ;
  dp[0][0] = s[0] - '0' ;
  dp[0][1] = 1 + 10 - s[0] + '0' ;
  for(int i = 1; i < s.size() ;i ++)
   {
     int x = s[i] - '0' ;
     dp[i][0] = min(dp[i - 1][0] + x , dp[i - 1][1] + x) ;
     dp[i][1] = min(dp[i - 1][0] + 10 - x + 1 , dp[i - 1][1] - 1 + 10 - x) ;
   }
   cout << min(dp[s.size() - 1][1] , dp[s.size() - 1][0] ) << endl ;
  return 0 ;
}
