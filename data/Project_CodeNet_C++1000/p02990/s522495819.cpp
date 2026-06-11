#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

ll mod = 1e9+7;
ll calc(ll a,ll p){
  if(p==0) return 1;
  if(p%2==0){
    ll d = calc(a,p/2);
    return d*d%mod;
  }else{
    return a*calc(a,p-1)%mod;
  }
}
ll comb(ll n, ll k){
  if(n<k) return 0;
  ll mo = 1;
  ll ch = 1;
  for(int i=0;i<k;i++){
    mo *= n-i;
    mo %= mod;
    ch *= i+1;
    ch %= mod;
  }
  ll res = mo*calc(ch,mod-2);
  return res%mod;
}
int main(){
  ll N,K; cin >> N >> K;
  for(int i=1;i<=K;i++){
    ll ans = comb(K-1,i-1)*comb(N-K+1,i);
    cout << ans%mod << endl;
  }
}
