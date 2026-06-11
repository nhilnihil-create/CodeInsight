#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,g=0,k=0,l=100000000000000000;
  cin>>N;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    g+=i;
  }
  for(int i=0;i<N;i++){
    k+=A[i];
    l=min(abs(g-k*2),l);
  }
  cout<<l<<endl;
}