#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>A(N);
  ll B=0;
  for(ll i=0;i<N;i++){
    cin>>A[i];
    B^=A[i];
  }
  for(ll i=0;i<N;i++){
    cout<<(B^A[i])<<" ";
  }
}