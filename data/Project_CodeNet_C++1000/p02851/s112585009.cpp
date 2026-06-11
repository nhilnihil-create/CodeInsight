#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
累積和おさえてもN^2
mapぽいんだけどどう管理するのか
5 4
1 4 2 3 5

1 0 2 3 1

1 0 2 0 1 //6

1 3 0 2 0 //3

1 1 1 1//5C2=10

Sj-Si)=j-i
Sj-j = Si-i

*/
int main(){
  ll N,K,ans=0; cin>>N>>K;
  vector<ll>A(N,0),S(N+1,0);
  map<ll,ll> M;
  for(ll i=0; i<N; i++) cin>>A[i];
  for(ll i=0; i<N; i++) S[i+1]=(S[i]+A[i]-1)%K;
  M[0]=1;
  for(ll i=1; i<=N; i++){
    if(i>=K) M[S[i-K]]--;//左端を捨てる
    ans+=M[S[i]];
//cout<<"i:"<<i<<" S[i]:"<<S[i]<<" M["<<S[i]<<"]:"<<M[S[i]]<<" ans:"<<ans<<endl;
    M[S[i]]++;
  }
  cout<<ans<<endl;
}