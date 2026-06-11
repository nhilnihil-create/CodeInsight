#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1000000007;
signed main(){
  int N,K,ans=0;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  for(int i=0;i<N;i++){
    int k=0,l;
    for(int j=0;j<i;j++)
      if(A[j]>A[i])
        k++;
    l=k;
    for(int j=i;j<N;j++)
      if(A[j]>A[i])
        l++;
    ans=(ans+k*K%M+K*(K-1)/2%M*l%M)%M;
  }
  cout<<ans<<endl;
}
