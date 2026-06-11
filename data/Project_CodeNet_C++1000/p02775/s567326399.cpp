#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;


string a;
const ll INF = 1e18;
ll dp[1000005][2];
int main () {
  string n;
  cin >> n;
  for(int i = 0; i < n.size(); i++) dp[i][0] = dp[i][1] = INF;
  dp[0][0] = 11 - (n[0] - '0');
  dp[0][1] = (n[0] - '0');
  for(int i = 1; i < n.size(); i++) {
    dp[i][0] = min(dp[i-1][0] + (9 - (n[i] - '0')),dp[i-1][1] + (11-(n[i]-'0')));
    dp[i][1] = min(dp[i-1][0]+(n[i]-'0'),dp[i-1][1]+(n[i]-'0'));
  }

  cout << min(dp[n.size()-1][0],dp[n.size()-1][1]) << endl;
}
    

    
