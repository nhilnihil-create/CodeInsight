#include <iostream>
#include <vector>

#define int long long

#define MOD 2019

signed main() {
  std::string s;
  std::cin >> s;

  int n = s.length();

  int cur = 0;
  int ans = 0;
  std::vector<int> dp(MOD, 0);
  dp[0] = 1;

  int pow = 1;
  for(int i = n-1; i >= 0; i--) {
    pow = (10*pow)%MOD;
    cur = (cur + (s[i]-'0')*pow)%MOD;

    ans += dp[cur];
    dp[cur]++;
  }

  std::cout << ans << std::endl;

  return 0;
}

