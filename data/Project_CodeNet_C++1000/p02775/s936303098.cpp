#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s; cin >> s; reverse(s.begin(), s.end());
  
  int dp[1000005][2]; dp[0][0] = 0; dp[0][1] = 1;
  for (int i = 0; i < s.length(); ++i) {
    dp[i+1][0] = min(dp[i][0], dp[i][1]+1)+s[i]-'0';
    dp[i+1][1] = min(dp[i][0], dp[i][1]-1)+10-(s[i]-'0');
  }
 
  cout << min(dp[s.length()][0], dp[s.length()][1]+1) << endl;
  return 0;
}
