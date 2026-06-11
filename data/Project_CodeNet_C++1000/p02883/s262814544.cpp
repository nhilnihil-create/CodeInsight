#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
ポイントふりわけ
というわけでもないか
均等に減らすわけでもなし
均等に減らすのがいいかな

11 14
3 1 4 1 5 9 2 6 5 3 5
8 9 7 9 3 2 3 8 4 6 2

31313323333=16
31414424434=10
11233444444
99887643322

最初にでかい順＊小さい順でわりあて
最小値を決めて調整とか
11233455569
99887643322

2分探索かも
*/
int main(){
  ll N,K,s=0; cin>>N>>K;
  vector<ll> A(N,0),F(N,0);
  for(ll i=0; i<N; i++){
    cin>>A[i];
    s+=A[i];
  }
  if(K>=s){
    cout<<0<<endl;
    return 0;
  }
  for(ll i=0; i<N; i++) cin>>F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll high=1e13, low=0;
  while(high-1>low){
    ll mid=(high+low)/2;
    ll k=K;
    for(ll i=0; i<N; i++){
      ll n=mid/F[i];
      k-=max(0LL,A[i]-n);
      if(k<0) break;   
    }
    if(k<0) low=mid;
    else high=mid;
  }
  cout<<high<<endl;
}