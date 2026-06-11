#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,D;
  cin>>N>>D;
  
  vector<vector<int>> vec(N,vector<int>(D));
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      cin>>vec[i][j];
    }
  }
  
  int ans=0;
  
  
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      int x=0;
      for(int k=0;k<D;k++){
        x+=(vec[i][k]-vec[j][k])*(vec[i][k]-vec[j][k]);
      }
      for(int l=0;l<200;l++){
        if(x==l*l){
          ans++;
          break;
        }
      }
    }
  }
  
  cout<<ans<<endl;
}