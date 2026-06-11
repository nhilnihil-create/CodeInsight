#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>A(N+1);
  vector<ll>B(N);
  for(ll i=0;i<N+1;i++)cin>>A[i];
  for(ll i=0;i<N;i++)cin>>B[i];
  ll ans=0;
  for(ll i=0;i<N;i++){
    if(A[i]<=B[i]){
      ans+=A[i];
      B[i]-=A[i];
    }else{
      ans+=B[i];
      B[i]=0;
    }
    if(A[i+1]<=B[i]){
      ans+=A[i+1];
      A[i+1]=0;
    }else{
      ans+=B[i];
      A[i+1]-=B[i];
      B[i]=0;
    }
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;

  
}