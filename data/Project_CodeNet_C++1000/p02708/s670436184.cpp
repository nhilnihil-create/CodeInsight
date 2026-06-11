#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K;
  cin>>N>>K;
  int L=(K-1)*K/2,R=(N*2-K+1)*K/2,j=0;
  for(;K<=N+1;K++){
    j=(j+R-L+1)%1000000007;
    L+=K;
    R+=N-K;
  }
  cout<<j<<endl;
}