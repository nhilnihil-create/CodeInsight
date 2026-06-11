#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  vector<long long> A(N+1),B(N);
  for(long long &i:A)
    cin>>i;
  for(long long &i:B)
    cin>>i;
  long long j=0,k=A[0];
  for(long long i=0;i<N;i++){
    if(k+A[i+1]-B[i]>0){
      j+=B[i];
      k=A[i+1]-max(B[i]-k,0LL);
    }else{
      j+=k+A[i+1];
      k=0;
    }
  }
  cout<<j<<endl;
}