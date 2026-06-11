#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
DPか再帰か
DPかな
oをxと仮定して無理だったら必須確定
でもN^2になる
とるの確定したら選択肢せばめていけば効率化？

11 3 2
ooxxxoxxxoo
xoxxxoxxxoo

ooxxxoxxxoo

oxxooxoxxo
1=1
2=1
6=2
10=3
11=3
一番遅いペースでとっておいて、それを上回っていればOK？
11=3
10=3
5 1 0
ooooo
一番速いペースと遅いペース、どっちもおさえとく

一番速いペースだけ抜いとく？
  ooxxxoxxxoo
は11111222233
お33222211111

抜いた前後C日だけ見とか
日数に余裕あったらむしろなし？
oの前後たして3になったらOK？あれ、いけそう？
*/
int main(){
  ll N,K,C,cnt=0,wait=0;
  string S;
  cin>>N>>K>>C>>S;
  vector<ll> DP1(N+10,0),DP2(N+10,0),ans(0,0);
  for(ll i=1; i<=N; i++){
    if(S[i-1]=='o' && wait==0){
      cnt++;
      wait=C;
    }
    else wait=max(0LL,wait-1);
    DP1[i]=cnt;
  }
  cnt=0,wait=0;
  for(ll i=N; i>0; i--){
    if(S[i-1]=='o' && wait==0){
      cnt++;
      wait=C;
    }
    else wait=max(0LL,wait-1);
    DP2[i]=cnt;
  }
  for(ll i=1; i<=N; i++) if(S[i-1]=='o' && DP1[i-1]+DP2[i+1]<K) ans.emplace_back(i);
  ll asz=ans.size();
  for(ll i=0; i<asz; i++) cout<<ans[i]<<endl;
}