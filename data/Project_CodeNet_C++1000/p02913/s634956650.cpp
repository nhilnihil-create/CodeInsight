#include<bits/stdc++.h>
using namespace std;

int N;
string S;

int dp[5000][5000];

signed main() {
  cin >> N >> S;

  for(int i=N-1; i>=0; i--) for(int j=N-1; j>=0; j--) {
    if(S[i]==S[j]) dp[i][j] = 1 + (((i<N-1)&&(j<N-1)) ? dp[i+1][j+1] : 0);
    else dp[i][j] = 0;
  }

  int ans = 0;
  for(int i=0; i<N; i++) {
    for(int j=i; j<N; j++) {
      if(dp[i][j] <= j-i) ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
