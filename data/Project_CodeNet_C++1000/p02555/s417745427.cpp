#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin >> s;

  vector<int> dp(2005);
  for (int i = 3; i <= 2000; i++)
  {
    int cnt = 0;
    for (int j = 3; j <= i; j++)
    {
      cnt+=dp[i-j];
      cnt%=1000000007;
    }
    dp[i] = cnt+1;
  }
  cout << dp[s] << endl;
}