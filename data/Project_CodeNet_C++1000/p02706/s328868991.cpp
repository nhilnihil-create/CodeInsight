#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,sum=0;
  cin>>N>>M;
  vector<int> A(M);
  for(int i=0; i<M; i++){
    cin>>A.at(i);
    sum+=A.at(i);
  }
  cout<<(N-sum>=0?N-sum:-1)<<endl;
}
  