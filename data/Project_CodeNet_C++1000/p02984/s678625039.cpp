#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>A(N+1,0);
  ll sum=0;
  for(ll i=1;i<=N;i++){
    cin>>A[i];
    sum+=A[i];
  }
  sum=sum/2;
  for(ll i=1;i<N;i++){
    if(i%2!=0)sum-=A[i];
  }
  //cout<<sum<<endl;
  ll x=A[N]-sum;
  cout<<2*x<<" ";
  for(ll i=1;i<N;i++){
    cout<<2*(A[i]-x)<<" ";
    x=A[i]-x;
  }
}