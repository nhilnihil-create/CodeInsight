#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()


void solve(){
  ll n, k;cin >> n >> k;
  vector<ll> a(n), f(n);
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,n) cin >> f[i];
  sort(ALL(a));sort(ALL(f));reverse(ALL(f));
  //for(auto x: af) cout << x.first << " " << x.second << endl; cout << endl;
  ll cost = (ll)1 << 45;
  ll cr = cost + 1, cl = -1, cm;
  while(cr-cl>1){
    cm = (cl+cr)/2;
    ll sk=0;
    FOR(i,0,n){
      if(a[i]*f[i]>cm){
        ll tmp = (a[i]*f[i]-cm+f[i]-1)/f[i];
        sk += tmp;
      }
    }
    if(sk>k) cl = cm;
    else cr = cm;
  }
  cout << cr << endl;
}

int main(){
  solve();
  return 0;
}