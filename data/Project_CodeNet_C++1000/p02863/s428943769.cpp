#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
setか
Tちょうどの時間は注文不可
3000
DPかな
とるとらないの2^3000はむり
一番ポイントの高いものは確実に最後にとれる
最後とも限らないのか

T-1までのとりかた
3000^2でDPか
DP[0]=0
3000*3000でとる？
最後、時間外にとるやつをどうするか
配列自体は6000まで、更新するのはT-1まで
上からみてく？
1個目をとるかとらないか、0とA0が更新？
最後にとる場合のパターンが漏れる
選択した箇所だけ加算するようにしないと

最初に時間がでかいのきたらばぐる
3 11
100 100
10 30
10 30
*/
int main(){
  ll N,T,oo=1e9; cin>>N>>T;
  vector<ll> DP(6050,-oo);
  DP[0]=0;
  vector<vector<ll>> Z(N,vector<ll>(2,0));
  ll high=0;
  for(ll i=0; i<N; i++){
    ll a,b; cin>>a>>b;
    Z[i][0]=a;
    Z[i][1]=b;
  }
  sort(Z.begin(), Z.end(), [](auto& x, auto& y){return x[0] < y[0];});
  for(ll j=0; j<N; j++){
    ll t=Z[j][0], d=Z[j][1];
    for(ll i=T-1; i>=0; i--){
      if(DP[i]==-oo) continue;
      DP[i+t]=max(DP[i+t],DP[i]+d);
    }
  }
  ll ans=0;
  for(ll i=0; i<=6000; i++) ans=max(ans,DP[i]);
  cout<<ans<<endl;
}