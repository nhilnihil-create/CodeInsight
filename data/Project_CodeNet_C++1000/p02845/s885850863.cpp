#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int main(){
  long N;cin>>N;
  vector<long>A(N),C(N,0);for(long i=0;i<N;i++)cin>>A[i];
  long ans=1;long t=3;
  for(long i=0;i<N;i++){
    if (A[i]==0){ans=ans*t%MOD;t--;}
    else {ans=ans*C[A[i]-1]%MOD;C[A[i]-1]--;}
    C[A[i]]++;
  }
  cout<<ans;
}

