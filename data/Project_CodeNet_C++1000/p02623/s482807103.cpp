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
  priority_queue<int> X;
  int best;
  for(int i=M;i>=0;i--){
    if(K>=B.at(i)){
      best=i;
      break;
    }
  }
  X.push(best);
  for(int i=1;i<=N;i++){
    if(A.at(i)>K) break;
    for(int j=best;j>=0;j--){
      if(K>=A.at(i)+B.at(j)){
        X.push(i+j);
        best=j;
        break;
      }
    }
  }
  cout<<X.top()<<endl;
}
    
