#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x;
  cin >> n >> m >> x;
  vector<vector<int>> text(n,vector<int>(m+1));
  for(int i=0;i<n;i++){
    cin >> text.at(i).at(m);
    for(int j=0;j<m;j++){
      cin >> text.at(i).at(j);
    }
  }
  
  int ans=1200001;
  for(int i=0;i<(1<<n);i++){
    int count=0;
    vector<int> learn(m);
    for(int j=0;j<n;j++){
      if((i>>j)&1){
        count+=text.at(j).at(m);
        for(int k=0;k<m;k++){
          learn.at(k)+=text.at(j).at(k);
        }
      }
    }
    bool flag=true;
    for(int j=0;j<m;j++){
      if(learn.at(j)<x){
        flag=false;
        break;
      }
    }
    if(flag)	ans=min(ans,count);
  }
  if(ans==1200001)	ans=-1;
  cout << ans;
}