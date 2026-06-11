#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;

int main() {
  int n,m;

  cin >> n >> m;

  vector<int> a(n+1,0);

  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    a[x]=1;
  }

  vector<long long> dp(n+1,0);
  dp[0] = 1;

  for(int i=0;i<n;i++) {
    if(a[i]==0) {
      if(a[i+1] == 0) {
        dp[i+1]+=dp[i];
        dp[i+1]%=M;
      }
      if(i+2<=n) {
        if(a[i+2] == 0) {
          dp[i+2]+=dp[i];
          dp[i+2]%=M;
        }
      }
    }
  }

  cout << dp[n] << endl;

  return 0;
}
