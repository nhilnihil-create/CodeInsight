#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> broken(n+1);
  rep(i,m) {
    int a;
    cin >> a;
    broken[a]=true;
  }
  vector<int> dp(n+1);
  dp[n]=1;
  for(int i=n-1; i>=0; i--) {
    if(broken[i]) dp[i]=0;
    else if(i==n-1) dp[i]=1;
    else dp[i]=(dp[i+1]+dp[i+2])%INF;
  }

  cout << dp[0] << endl;
  return 0;
}
