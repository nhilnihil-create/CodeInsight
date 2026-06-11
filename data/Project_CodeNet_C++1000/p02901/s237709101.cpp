#include<bits/stdc++.h>
using namespace std;

const int INF=(1 << 20);

int N, M;
int a[1000], b[1000];
int c[1000][13];
int cbit[1000];

int dp[4096];

signed main() {
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    cin >> a[i] >> b[i];
    for(int j=0; j<b[i]; j++) {
      cin >> c[i][j];
      cbit[i] |= 1<<(c[i][j]-1);
    }
  }

  fill(dp, dp+4096, INF);

  dp[0] = 0;
  for(int i=0; i<M; i++) for(int opened=0; opened<(1<<N); opened++) 
      dp[opened | cbit[i]] = min(dp[opened | cbit[i]], dp[opened] + a[i]);

  cout << (dp[(1<<N) - 1] == INF ? -1 : dp[(1<<N) - 1]) << endl;
}
