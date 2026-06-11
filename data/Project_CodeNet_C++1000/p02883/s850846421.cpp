#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

vector<ll> a(mx);
vector<ll> f(mx);
ll n,k;

bool finish(ll x){
  ll cnt=0;
  rep(i,n){
    if(a[i]*f[i]<=x) continue;
    if(f[i]>x){ cnt += a[i]; continue; }
    cnt += a[i]-(x/f[i]);
  }
  return cnt<=k;
}
 
int main(){
  cin >> n >> k;
  a.resize(n);
  f.resize(n);
  ll sum = 0;
  rep(i,n){ cin >> a[i]; sum += a[i]; }
  rep(i,n) cin >> f[i];
  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());

  if(sum<=k){ cout << 0 << endl; return 0; }

  ll l=0,r=1e12,mid=(r+l)/2;
  while(r-l>1){
    mid=(r+l)/2;
    if(finish(mid)){ r=mid; }else{ l=mid; }
  }
  ll ans = r;
  cout << ans << endl;
  return 0;
}
