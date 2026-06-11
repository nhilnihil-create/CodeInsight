#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int p(int A,int B){
  if(!B)return 1;
  if(B%2)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(K+1);
  int ans=0;
  for(int i=K;i>0;i--){
    A[i]=p(K/i,N);
    for(int j=i*2;j<=K;j+=i)A[i]=(A[i]-A[j]+mod)%mod;
    ans=(ans+A[i]*i%mod)%mod;
  }
  cout<<ans<<endl;
}