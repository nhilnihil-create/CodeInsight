#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;long K;cin>>N>>M>>K;
  vector<long> A(N+1,0),B(M+1,0);
  for(int i=1;i<=N;i++){
    long W;cin>>W;
    A.at(i)=W+A.at(i-1);
  }
  for(int i=1;i<=M;i++){
    long W;cin>>W;
    B.at(i)=W+B.at(i-1);
  }
  int left=-1;
  int right=N+M+1;
  while(left<right){
    int X=(left+right)/2;
    int ableA=min(N,X);
    int ableB=min(M,X);
    bool can=false;
    if(N>=M){
      for(int i=X-ableB;i<=ableA;i++){
        long time=A.at(i)+B.at(X-i);
        if(time<=K){
          can=true;
          break;
        }
      }
    }
    else{
      for(int i=X-ableA;i<=ableB;i++){
        long time=B.at(i)+A.at(X-i);
        if(time<=K){
          can=true;
          break;
        }
      }
    }
    if(can) left=X+1;
    else right=X;
  }
  cout<<max(left-1,0)<<endl;
}
