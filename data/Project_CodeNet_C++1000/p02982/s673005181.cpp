#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D;
  cin >> N >> D;
  
  vector<vector<int>> X(N,vector<int>(D));
  
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      cin >> X.at(i).at(j);
    }
  }
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      int d=0;
      for(int k=0;k<D;k++){
        d += (X.at(i).at(k)-X.at(j).at(k))*(X.at(i).at(k)-X.at(j).at(k));
      }
      
      bool h=false;
      
      for(int k=1;k<sqrt(d)+1;k++){
        if(k*k==d)h=true;
      }
      
      if(h==true)ans++;
    }
  }
  
  cout << ans << endl;
}