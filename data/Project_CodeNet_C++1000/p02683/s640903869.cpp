#include <bits/stdc++.h>
using namespace std;
const int INF=10001001;
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  vector<vector<int>> algo(n,vector<int>(m));
  vector<int> cost(n);
  for(int i=0;i<n;i++){
    cin>>cost[i];
    for(int j=0;j<m;j++){
      cin>>algo[i][j];
    }
  }
  int kotae=INF;
  for(int i=0;i<(1<<n);i++){
    int ans=0;
    vector<int> understand(m);
    for(int j=0;j<n;j++){
      if((i>>j)&1){
        ans+=cost[j];
        for(int k=0;k<m;k++){
          understand[k]+=algo[j][k];
        }
      }
    }
    bool ok=true;
    for(int j=0;j<m;j++){
      if(understand[j]<x)ok=false;
    }
    if(ok){
      kotae=min(kotae,ans);
    }
  }
  if(kotae!=INF){
    cout<<kotae<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}