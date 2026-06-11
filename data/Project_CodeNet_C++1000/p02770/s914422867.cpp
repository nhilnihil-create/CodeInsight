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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;


int main(){
  ll k,q;
  cin >> k >> q;
  vector<ll> d(k);
  rep(i,k){
    cin >> d[i];
  }

  while(q--){
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll> z(k+1,0);
    vector<ll> r(k+1,0);
    rep(i,k){
      z[i+1] += z[i];
      if(d[i]%m==0){
        z[i+1]++;
      }
      r[i+1] = r[i] + d[i]%m;
    }
    ll ans = n-1 - (x%m+(r[k]*((n-1)/k))+r[(n-1)%k])/m - ((z[k]*((n-1)/k))+z[(n-1)%k]);
    ll A = (x+(r[k]*((n-1)/k))+r[(n-1)%k]);
    ll Z = ((z[k]*((n-1)/k))+z[(n-1)%k]);
    cout << ans << ln;
  }


  return 0;
}