#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x;
  cin >> n >> m >> x;
  long long ans=99999999999999999;
  vector<vector<int>> data(13,vector<int>(13));
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=m;j++){
      cin >> data.at(i).at(j);
      }
     }
  
  bool over = true;
  
  //bit全探索
  for(int bit=0;bit < (1<<n) ;bit++){
    vector<long long> sum(14,0);
    long long money=0;
    over = true;
    for(int i=0;i<n;i++){
    if(bit & (1<<i)){
      money += data.at(i).at(0);
    
      for(int j=1;j<=m;j++){
        sum[j-1] += data.at(i).at(j);
      
      }
    }
    }
      for(int i=0;i<m;i++){
        if(sum[i]<x) over = false;
       
      }
      
    
    if(over) ans = min(ans,money);

  
     
  }
        if(ans==99999999999999999) cout << -1 << endl;
    else cout << ans << endl;
  }