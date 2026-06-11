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

  ll n;cin>>n;
  ll a[n];rep(i,0,n)cin>>a[i];
  ll sum=accumulate(a,a+n,(ll)0);
  ll mi=sum;
  ll s=0;
  rep(i,0,n){
    s+=a[i];
    chmin(mi,abs(sum-2*s));
  }

  out(mi);


  
  return 0;
}
