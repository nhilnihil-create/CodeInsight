#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  int size = 1 << n;
  int dp[size];
  for (int i=0; i<size; i++) dp[i] = 1e9;
  for (int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    bool can_open[n];
    for (int j=0; j<n; j++) {
      can_open[j] = false;
    }
    for (int j=0; j<b; j++) {
      int c;
      cin>>c;
      can_open[c-1] = true;
    }
    int state = 0;
    for (int j=n-1; j>=0; j--) {
      state *= 2;
      if (can_open[j]) {
        ++state;
      }
    }
    dp[state] = min(a, dp[state]);
  }
  for (int i=0; i<size; i++) {
    for (int j=0; j<size; j++) {
      if (dp[i] < 1e9 && dp[j] < 1e9) {
        dp[i|j] = min(dp[i] + dp[j], dp[i|j]);
      }
    }
  }
  if (dp[size-1] == 1e9) {
    cout<<-1<<endl;
  } else {
    cout<<dp[size-1]<<endl;
  }
}