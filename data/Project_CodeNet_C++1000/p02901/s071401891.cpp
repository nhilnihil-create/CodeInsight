#include <bits/stdc++.h>

using namespace std;
const int INF=1e9;

int main(){
  int n, m, a[1009], b[1009], c[1009][15];
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    for(int j=0;j<b[i];j++)cin >> c[i][j], c[i][j]--;
  }
  int dp[5000];
  for(int i=0;i<1<<n;i++)dp[i]=INF;
  dp[0] = 0;
  for(int i=0;i<m;i++){
    int key = 0;
    for(int j=0;j<b[i];j++)key |= (1<<c[i][j]);
    for(int j=0;j<1<<n;j++){
      int next = j | key;
      dp[next] = min(dp[next], dp[j] + a[i]);
    }
  }
  cout << (dp[(1<<n)-1]==INF?-1:dp[(1<<n)-1]) << endl;
}

