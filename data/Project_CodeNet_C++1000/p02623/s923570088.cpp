#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M,K;
  cin >> N >> M >> K;
  vector<ll> A(N),B(M);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  for(ll i=0;i<M;i++){
    cin >> B[i];
  }
  ll sum=0;
  ll Anum=-1,Bnum=-1;
  for(ll i=0;i<N;i++){
    if(sum+A[i]>K){
      break;
    }
    sum+=A[i];
    Anum=i;
  }
  for(ll i=0;i<M;i++){
    if(sum+B[i]>K){
      break;
    }
    sum+=B[i];
    Bnum=i;
  }
  if(Anum+1==N && Bnum+1==M){
    cout << N+M << endl;
    return 0;
  }
  ll ans=Anum+Bnum+2;
  while(Anum!=-1){
    sum-=A[Anum];
    --Anum;
    for(ll i=Bnum+1;i<M;i++){
      if(sum+B[i]>K){
      break;
      }
      sum+=B[i];
      Bnum=i;
    }
    ans=max(ans,Anum+Bnum+2);
  }
  cout << ans << endl;
}