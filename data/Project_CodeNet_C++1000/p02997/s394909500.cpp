#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
  ll N,K;
  cin>>N>>K;
  ll g=(N-2ll)*(N-1ll)/2ll;
  queue<P>qu;
  if(g<K){cout<<-1;return 0;}
  else{
    
    ll memo=g-K;
    rep(i,N-1){
      qu.push(P(N,i+1));
    }
    int flag=0;
    for(int i=1;i<=N-1;i++){
      for(int j=i+1;j<=N-1;j++){
        if(memo==0){flag=1;}
        if(flag==1){continue;}
        qu.push(P(i,j));
        memo--;
      }
      if(flag==1){continue;}
    }
  }
  cout<<qu.size()<<endl;
  while(!qu.empty()){
    auto t=qu.front();
    qu.pop();
    cout<<t.first<<' '<<t.second<<endl;
  }
  
}
