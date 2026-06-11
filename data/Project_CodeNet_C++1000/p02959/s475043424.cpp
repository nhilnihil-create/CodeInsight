#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,count=0;
  cin>>N;
  vector<ll> A(N+1),B(N);
  for(int i=0; i<N+1; i++){
    cin>>A[i];
  }
  for(int i=0; i<N; i++){
    cin>>B[i];
  }
  for(int i=0; i<N; i++){
    if(A[i]>=B[i]){
      count+=B[i];
      A[i]-=B[i];
    }
    else{
      count+=A[i];
      if(A[i+1]>=B[i]-A[i]){
        count+=B[i]-A[i];
        A[i+1]-=B[i]-A[i];
      }
      else{
        count+=A[i+1];
        A[i+1]=0;
      }
      A[i]=0;
    }
  }
  cout<<count<<endl;
}
        