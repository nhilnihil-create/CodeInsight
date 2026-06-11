#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,m,v,p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  rep(i,n)cin >> a[i];
  sort(ALL(a),greater<int>());
  ll l = p-1,r = n;
  while(r-l > 1){
    ll k = 1ll*m*(n-v);
    int i = (l+r)/2;
    for(int j = p-1;j < i;j++){
      if(abs(a[j]-a[i]) > m)k = 0;
      k -= 1ll*abs(a[j]-a[i]);
    }
    if(k >= 0)l = i;
    else r = i;
  }
  cout << r << endl;



  return 0;
}