#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,D,norm,sum=0;
  cin >> N >> D;
  int X[N][D];
  
  for(int i=0;i<N;i++){
    for(int k=0;k<D;k++){
      cin >> X[i][k];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      norm = 0;
      for(int k=0;k<D;k++){
        norm += (X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      }
      bool sq = false;
      for(int l=0;l<=norm;l++){
        if(norm == l*l){
          sq=true;
        }
      }
      if(sq){
        sum++;
      }
    }
  }
  cout << sum << endl;
  return 0;
}