#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

#define increment(a, b) (a == '.' && b == '#')

int find_root(int h, int w)
{
    
  unsigned int dp[h][w];
  string s[h];
  REP(i, h)
  {
    cin >> s[i];
    REP(j, w)
    {
      dp[i][j] = -1;
    }
  }
  
  dp[0][0] = (s[0][0] == '#');
  
  REP(i, h)
  {
    REP(j, w)
    {
      if(i != h-1)
      {
		dp[i+1][j] = dp[i][j] + increment(s[i][j], s[i+1][j]);
      }
      if(j != w-1)
      {
	  	dp[i][j+1] = min(dp[i][j+1], dp[i][j] + increment(s[i][j], s[i][j+1]));
      }
    }
  }
    
  return dp[h-1][w-1];
}

int main()
{
  int h,w;
  cin >> h >> w;
  
  cout << find_root(h, w) << endl;
  return 0;
}