#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
  //unordered_map<string,long long int> dp;
  long long int x, ans = 0;
  cin >> x;
  for(int i=1; i <= x; i++)
    for(int j=1; j <= x; j++)
    	for(int k=1; k <= x; k++)
        {
          /*string temps = to_string(i) + to_string(j) + to_string(k);
          sort(temps.begin(), temps.end());
          if(dp[temps] != 0)
            ans = ans + dp[temps];
          else {*/
            long long int gcd = __gcd(__gcd(i,j), k);
            //dp[temps] = gcd;
            ans = ans + gcd;
          //}
        }
  cout << ans;
  return 0;
}
   