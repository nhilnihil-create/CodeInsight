#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> cost(m);
  vector<int> box(m,0);
  for(int i=0; i<m; ++i){
    int mi;
    cin >> cost[i] >> mi;
    for(int j=0; j<mi; ++j){
      int x;
      cin >> x;
      --x;
      box[i] += (1<<x);
    }
  }
  vector<int> dp((1<<n),INF);
  dp[0] = 0;
  for(int i=0; i<(1<<n); ++i) for(int j=0; j<m; ++j){
    dp[i|box[j]] = min(dp[i|box[j]], dp[i]+cost[j]);
  }
  if(dp[(1<<n)-1] == INF) cout << -1 << endl;
  else cout << dp[(1<<n)-1] << endl;
}