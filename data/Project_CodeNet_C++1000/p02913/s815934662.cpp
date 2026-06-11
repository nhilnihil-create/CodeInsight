#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
重ならずに2回現れる文字列の最長かな
さっぱりわからん
しゃくとり？
でも開始文字からずれると
N^3ぐらいになりそう

TLE。
ちょっとの効率化

abcdab

*/
int main(){
  ll N,ans=0; cin>>N;
  string S; cin>>S;
  for(ll i=1; i<N; i++){//文字幅
    ll tmp=0;
    for(ll j=0; j+i<N; j++){
      tmp=(tmp+1)*(S[j]==S[i+j]);
      ans=max(ans,min(tmp,i));
    }
  }
  cout<<ans<<endl;
}