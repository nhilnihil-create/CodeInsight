#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int K,N,mx=0;
  cin>>K>>N;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  for(int i=0;i<N;i++)mx=max(mx,(A[(i+1)%N]-A[i]+K)%K);
  cout<<K-mx<<endl;
}