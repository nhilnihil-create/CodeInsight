#include <iostream>
#include <vector>

void solve(std::string S)
{
  std::vector<long long> dp(13, 0);
  dp[0] = 1;
  long long num = 1;
  long long mod = 1e9 + 7;
  for (int i = S.size()-1; i >= 0; i--)
  {
    std::vector<long long> new_dp(13, 0);
    if(S[i]=='?')
    {
      for (int n = 0; n < 10; n++)
      {
        for (int m = 0; m < 13; m++)
        {
          new_dp[(m+n*num)%13] += dp[m];
          new_dp[(m+n*num)%13]%=mod;
        }
      }

    }
    else
    {
      int n = S[i] - '0';
      for (int m = 0; m < 13; m++)
      {
        new_dp[(m+n*num)%13] += dp[m];
        new_dp[(m+n*num)%13]%=mod;

      }
    }
    dp = new_dp;
    num *= 10;
    num %= 13;
  }
  std::cout << dp[5] << std::endl;
}

int main(void)
{
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}
