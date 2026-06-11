#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int my_pow(int A,int B){
  if(B==0)
    return 1;
  if(B%2==1)
    return my_pow(A,B-1)*A%mod;
  int C=my_pow(A,B/2);
  return C*C%mod;
}
signed main(){
  int N,K;
  vector<int> A(2010);
  cin>>N>>K;
  int M=N-K;
  A[0]=1;
  for(int i=1;i<2010;i++)
    A[i]=A[i-1]*i%mod;
  for(int i=1;i<=K;i++){
    if(i>M+1)
      puts("0");
    else
      cout<<(A[M+1]*my_pow(A[M+1-i]*A[i]%mod,mod-2)%mod)*
            (A[K-1]*my_pow(A[K-i]*A[i-1]%mod,mod-2)%mod)%mod<<endl;
  }
}