#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D,cnt=0;
  cin>>N>>D;
  vector<vector<double>> X(N,vector<double>(D));
  for(int i=0; i<N; i++){
    for(int j=0; j<D; j++){
      cin>>X[i][j];
    }
  }
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      double sum=0;
      for(int k=0; k<D; k++){
        sum+=pow(X[i][k]-X[j][k],2);
      }
      sum=sqrt(sum);
      if(ceil(sum)==floor(sum)){
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
}