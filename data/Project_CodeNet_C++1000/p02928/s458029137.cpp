#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define each(i,mp) for(auto& i:mp)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const ll m=1LL<<32;

int main(){

  ll n,k;cin>>n>>k;
  ll a[n];rep(i,0,n)cin>>a[i];
  ll b[2*n];
  rep(i,0,n){
    b[i]=b[n+i]=a[i];
  }

  ll one[n];
  rep(i,0,n){
    ll count=0;
    rep(j,i+1,n){
      if(a[i]>b[j])count++;
    }
    one[i]=count;
  }

  ll multi[n];
  rep(i,0,n){
    ll count=0;
    rep(j,i+1,n+i){
      if(b[j]>b[n+i])count++;
    }
    multi[i]=count;
  }

  ll ans=0;
  rep(i,0,n){
    ans+=(((k*(k-1)/2)%mod)*multi[i])%mod;
    ans%=mod;
    (ans+=(one[i]*k)%mod)%=mod;
  }

  out(ans);

  return 0;
}
