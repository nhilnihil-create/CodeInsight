#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,ans=12345678;
  cin >> n >> m >> x;
  vector<vector<int>> A(n,vector<int>(m));
  vector<int> c(n);
  for(int i=0;i<n;i++){
    cin >> c[i];
    for(int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  for(int mask=0;mask<(1<<n);mask++){
    vector<int> lev(m);
    int cost=0;
    for(int i=0;i<n;i++){
      if(mask&(1<<i)){
        cost+=c[i];
        for(int j=0;j<m;j++)lev[j]+=A[i][j];
      }
    }
    bool t=true;
    for(int j=0;j<m;j++)if(lev[j]<x)t=false;
      if(t)ans=min(ans,cost);
  }
  if(ans==12345678)cout << -1 << endl;
  else cout << ans << endl;
}
