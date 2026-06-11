#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  int ans=0;
  for(int i=0;i<N;i++){
    int n=0;
    for(int j=0;j<i;j++)
      if(A[j]>A[i])n++;
    int m=n;
    for(int j=i+1;j<N;j++)
      if(A[j]>A[i])m++;
    ans=(ans+K*(K-1)/2%mod*m%mod+n*K)%mod;
  }
  cout<<ans<<endl;
}