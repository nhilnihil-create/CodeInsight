#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,  m, x;
  cin>>n>>m>>x;
  vector<vector<int>> v(n, vector<int>(m));
  vector<int> c(n);
  for(int i=0; i<n; ++i){
    cin>>c[i];
    for(int j=0; j<m; ++j){
      cin>>v[i][j];
    }
  }

  int res=INT_MAX;
  for(int mask=0; mask<(1<<n); ++mask){
    vector<int> level(m);
    int cost=0;
    for(int i=0; i<n; ++i){
      if((mask>>i) & 1){
        cost += c[i];
        for(int j=0; j<m; ++j){
          level[j] += v[i][j];
        }
      }
    }
    bool flag=true;
    for(int i=0; i<m; ++i){
      if(level[i] < x) flag=false;
    }
    if(flag) res=min(res, cost);
  }
  if(res == INT_MAX) cout<<"-1"<<endl;
  else cout<<res<<endl;
}
