#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

std::string s1, s2;
int dp[1001][1001];

int main()
{
  std::cin >> s1 >> s2;

  rep( i, s1.size()+1 )
    dp[i][0] = i;
  rep( j, s2.size()+1 )
    dp[0][j] = j;

  repi( i, 1, s1.size()+1 ) repi( j, 1, s2.size()+1 )
    dp[i][j] = std::min( dp[i-1][j-1]+(s1[i-1]!=s2[j-1]), std::min( dp[i-1][j]+1, dp[i][j-1]+1 ) );

  std::cout << dp[s1.size()][s2.size()] << std::endl;

  return 0;
}