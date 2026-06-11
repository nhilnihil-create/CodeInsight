#include<bits/stdc++.h>
using namespace std;


long long func(long long N,long long A){
  long long res=A*(2*N-A+1)/2-A*(A-1)/2+1;
  return res;
}

int main(){
  long long N,K,mod=1000000007;
  cin >> N >> K;
  long long sum=0;
  for(long long i=K;i<N+2;i++){
    long long A=func(N,i)%mod;
    sum=(sum+A)%mod;
  }
  cout << sum <<endl;
}