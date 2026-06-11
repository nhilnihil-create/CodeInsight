#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N,0),C(0);
  for(int &i:A)
    cin>>i;
  for(int i=N;i>0;i--){
    int cnt=0;
    for(int j=2;i*j<=N;j++)
      cnt+=B[i*j-1];
    B[i-1]=(A[i-1]+cnt)%2;
  }
  for(int i=0;i<N;i++)
    if(B[i])
      C.push_back(i+1);
  cout<<C.size()<<endl;
  for(int i=0;i<(int)C.size();i++){
    cout<<C[i];
    if(i==C.size()-1)
      cout<<endl;
    else
      cout<<' ';
  }
}