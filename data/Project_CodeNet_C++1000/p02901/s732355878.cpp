#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
箱すくな
鍵の有無で2^1000は無理
箱ごとに鍵をいれて、最安値を順番に。12!通り？
なんかだめそう

bit探索とDP組み合わせ、すご。
2^12=4096
鍵1本につき毎回4096回DPしてる
|= いみわかった

自分が1001
1=min(1,自分)
10=min(10)
あくまで自分との論理和だけ更新で、4096通りは全部ながす
いや、でも0001を更新するには？
論理積も更新
1001&0001=0001
*/
int main(){
  ll N,M,oo=4e9; cin>>N>>M;
  vector<ll> A(M+1,0), B(M+1,0), DP(5000,oo);
  DP[0]=0;
  for(ll i=1; i<=M; i++){
    ll a,b; cin>>a>>b;
    A[i]=a;
    ll n=0;
    for(ll j=0; j<b; j++){
      ll c; cin>>c;
      n|=(1<<(c-1));
    }
    B[i]=n;//1 2 4 = 11が入る
  }
  
  for(ll i=1; i<=M; i++){//鍵
    for(ll j=1; j<(1<<N); j++){//bit
      ll x=B[i]&j;
      ll y=B[i]|j;
      DP[x]=min(DP[x], A[i]);
      DP[y]=min(DP[y], DP[j]+A[i]);
    }
  }
  ll ans=DP[(1<<N)-1];
  if(ans==oo) ans=-1;
  cout<<ans<<endl;
}