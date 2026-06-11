#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

ll modpow(ll b, ll i){
  ll s=1;
  while(i){
    if(i%2) s=(s*b)%MOD;
    b=(b*b)%MOD; i/=2;
  }
  return s;
}
ll nCr(ll n, ll r){
  ll m1=1,m2=1; r=min(r,n-r);
  for(int i=0; i<r; i++){
    m1=(m1*(n-i))%MOD; m2=(m2*(r-i))%MOD;
  }
  return (m1*modpow(m2,MOD-2))%MOD;
}

void solve(){
  int n,k; cin >>n >>k;
  for(int i=0; i<k; i++){
    if(n-k<i) cout <<0<<endl;
    else cout <<nCr(k-1,i)*nCr(n-k+1,i+1)%MOD<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}