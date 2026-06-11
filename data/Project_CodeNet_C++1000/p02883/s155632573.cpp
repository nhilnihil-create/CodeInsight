#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k; cin >> n >> k;
  vector<ll> a(n), f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(all(a)); sort(all(f),greater<ll>());

  ll check=0;
  rep(i,n) check+=a[i];
  if(check <= k){ cout << "0"; return 0;}
  
  vector<pair<ll,ll>> p;
  rep(i,n) p.emplace_back(make_pair(a[i], f[i]));
  
  ll l = 0, r = 1000006000000;
  
  while(1){
    ll m = (l+r)/2;
    ll syugyo = 0;
    rep(i,n){
      if(m < p[i].first * p[i].second){
        syugyo += p[i].first - ll(m/p[i].second);
      }
    }
    if(syugyo > k) l = m + 1;
    else r = m;
    if(abs(r - l) <= 1) break;
  }

  ll c = 0;
  rep(i,n){
    if(l < p[i].first * p[i].second){
        c += p[i].first - ll(l/p[i].second);
    }
  }
  if(c <= k) cout << l << endl;
  else cout << r << endl;
  
  
  return 0;
}