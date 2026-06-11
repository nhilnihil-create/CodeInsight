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

void solve(){
  int n; cin >>n;
  vector<ll>a(n); ll p[60],t=1,ans=0;
  for(int i=0; i<n; i++) cin >>a[i];
  for(int i=0; i<60; i++){
    p[i]=t;
    t=(t*2)%MOD;
  }
  for(int i=0; i<60; i++){
    ll odd=0,even=0;
    for(int j=0; j<n; j++){
      if(a[j]%2) odd++;
      else even++;
      a[j]/=2;
    }
    ll cnt=(odd*even)%MOD;
    ans+=cnt*p[i]; ans%=MOD;
  }
  cout <<ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}