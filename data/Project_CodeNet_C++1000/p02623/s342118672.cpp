#include<bits/stdc++.h>
using namespace std;

int main(){
 int N,M,K;
  long long sum=0;
  cin >> N >> M >> K;
  vector<int> A(N),B(M);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int j=0;j<M;j++){
    cin >> B.at(j);
    sum+=B.at(j);
  }
  int ans=0;
  int j=M;
  for(int i=0;i<N+1;i++){
    while(j>0 && sum>K){
      j--;
      sum-=B.at(j);
    }
    if(sum>K){
      break;
    }
    ans=max(ans,i+j);
    if(i==N){
      break;
    }
    sum+=A.at(i);
  }
  cout << ans << endl;
}
    