#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  int a=0;
  int B=0;
  for(int i=1;i<=N;i++){
    a=a+i-1;
  }
  for(int j=1;j<=M;j++){
    B=B+j-1;
  }
  cout<<a+B<<endl;
}