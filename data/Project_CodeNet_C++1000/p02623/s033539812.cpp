#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,M,K;cin>>N>>M>>K;
  vector<long> A(N+1),B(M+1);
  A.at(0)=0;
  for(long i=1;i<=N;i++){
    long X;cin>>X;
    A.at(i)=X+A.at(i-1);
  }
  B.at(0)=0;
  for(long i=1;i<=M;i++){
    long X;cin>>X;
    B.at(i)=X+B.at(i-1);
  }
  long best;
  for(long i=M;i>=0;i--){
    if(B.at(i)<=K){
      best=i;
      break;
    }
  }
  priority_queue<long> ans;
  ans.push(best);
  long read;
  for(long i=1;i<=N;i++){
    if(A.at(i)>K) break;
    for(long j=best;j>=0;j--){
      if(A.at(i)+B.at(j)<=K){
        read=i+j;
        best=j;
        break;
      }
    }
    ans.push(read);
  }
  cout<<ans.top()<<endl;
}
