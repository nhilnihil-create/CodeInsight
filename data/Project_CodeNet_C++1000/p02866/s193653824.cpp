#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
const ll mod=998244353;

int main() {
 ll n; cin >> n;
  vector<ll> cnt(n,0);
 rep(i,n){
  ll a; cin >> a;
  if((i==0 && a!=0) || (i!=0 && a==0)){
    cout << 0 << endl;
    return 0;
  }

  cnt[a]++;
 }
 ll d=1;
 for(ll i=1;i<n;i++){
   if(cnt[i-1]==0 && cnt[i]!=0){
     cout << 0 << endl;
     return 0;
   }
    for(ll j=0;j<cnt[i];j++){
      d*=cnt[i-1];d%=mod;
    }
 }
 cout << d%mod << endl;
}
