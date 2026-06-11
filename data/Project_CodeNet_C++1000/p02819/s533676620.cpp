#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin>>X;
  int N=1000000;
  vector<int> A(N);
  A.at(0)=1;
  for(int i=2; i<=N/2; i++){
    for(int j=2; i*j<=N; j++){
      if(A.at(i*j-1)==0){
        A.at(i*j-1)=1;
      }
    }
  }
  for(int i=0; i<N; i++){
    if(A.at(i)==0&&i+1>=X){
      cout<<i+1<<endl;
      return 0;
    }
  }
  return 0;
}