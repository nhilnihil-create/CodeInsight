#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,Q;
  cin>>N>>K>>Q;
  vector<int> A(N);
  for(int i=0;i<Q;i++){
    int j;
    cin>>j;
    A[j-1]++;
  }
  for(int i:A){
    if(K+i-Q>0)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}