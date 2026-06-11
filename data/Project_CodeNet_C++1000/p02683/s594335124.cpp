#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;



int main() {
  int n,m,x;
  cin >> n >> m >> x;
  vector<vector<int>> data(n, vector<int>(m));
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c.at(i);
    for (int j = 0; j < m; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int ans=1e7;
  int all=1<<n;
  for(int i=0;i<all;i++){
    vector<int> level(m);
    int cost=0;
    for(int j=0;j<n;j++){
      if((i>>j)&1){
        cost+=c.at(j);
        for(int k=0;k<m;k++){
          level[k]+=data[j][k];
        }
      }
    }
    bool ok=true;
    for(int k=0;k<m;k++){
      if(level[k]<x) ok=false;
    }
    if(ok) ans=min(ans,cost);
  }
  if(ans==1e7) cout << -1 << endl;
  else cout << ans << endl;
}

