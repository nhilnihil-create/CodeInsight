#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
何ループかをみる。
ループじゃないやつを10^5個別に探してく
それだと順番考慮もれてるか
2回つなげて、何文字目にあるかを調べるべきか

そうでもない。1文字ずつlowerで
*/
int main(){
  string S,T; cin>>S>>T;
  vector<vector<ll>> A(30);
  ll Ssz=S.size(), Tsz=T.size(), Ssz2=Ssz*2;
  ll loop=0;
  S+=S;
  for(ll i=0; i<Ssz2; i++){
    ll n=S[i]-'a';
    A[n].push_back(i+1);
  }
// now=2
// 2,3,5,6 
  //初期位置
  ll now=0, next=0;
  ll n=T[0]-'a';
  if(A[n].size()==0){
    cout<<-1<<endl;
    return 0;
  }  
  now=A[n][0];
  ll ans=now;
  for(ll i=1; i<Tsz; i++){
    n=T[i]-'a';
    auto IT=upper_bound(A[n].begin(), A[n].end(), now);
    if(IT==A[n].end()){
      cout<<-1<<endl;
      return 0;
    }
    ll next=*IT;
    ans+=next-now;
    if(next>Ssz) next-=Ssz;
    now=next;
  }
  cout<<ans<<endl;
}