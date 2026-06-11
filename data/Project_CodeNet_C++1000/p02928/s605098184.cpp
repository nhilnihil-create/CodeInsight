#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  ll n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll cnt=0;
  rep(i,n){
    for(int j=i; j<n; j++){
      if(a[i]>a[j]) cnt++;
    }
  }
  ll ans=(k*cnt)%MOD;
  cnt=0;
  rep(i,n)rep(j,n){
    if(a[i]>a[j]) cnt++;
  }
  ans+=(k-1)*k/2%MOD*cnt%MOD;
  cout << ans%MOD << endl;
  return 0;
}
