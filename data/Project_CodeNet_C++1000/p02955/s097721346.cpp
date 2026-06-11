#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
最大でも総和か
総和-MAXが動かす最大回数
N=500なら全探索か
Kがでかいからだめか
総和の約数について全通りしらべるかな
4 5
10  1  2 22

+4 +6 +5 +6
-3 -1 -2 -1
差分とる、マイナスの小さいほうからとって、残りのプラスの総和と等しくなったら手数
*/
int main(){
  ll N,K; cin>>N>>K;
  vector<ll> A(N,0),B;
  vector<pair<ll,ll>> P(N,make_pair(0,0));
  for(ll i=0; i<N; i++) cin>>A[i];
  ll high=0, sum=0;
  for(ll i=0; i<N; i++){
    sum+=A[i];
    high=max(high,A[i]);
  }
  //Bに約数入れる
  ll end=sqrt(sum);
  for(ll i=1; i<=end; i++){
    if(sum%i==0){
      B.emplace_back(i);
      if(i==sum/i) break;
      B.emplace_back(sum/i);
    }
  }
  sort(B.begin(), B.end(), greater<ll>());
  ll Bsz=B.size();
  for(ll i=0; i<Bsz; i++){
  //プラマイ表つくる
    ll Psum=0, Lsum=0;
    for(ll j=0; j<N; j++){
      ll L=A[j]%B[i];
      P[j].first=B[i]-L;
      P[j].second=L;
      Psum+=P[j].first;
    }
    sort(P.begin(), P.end(), [](auto& x, auto& y){return x.second < y.second;});
    ll k=K, n=0;
    while(k>=0 && Psum!=Lsum){
      Psum-=P[n].first;
      Lsum+=P[n].second;
      k-=P[n].second;
      n++;
    }
    if(k>=0){
      cout<<B[i]<<endl;
      return 0;
    }
  }
}