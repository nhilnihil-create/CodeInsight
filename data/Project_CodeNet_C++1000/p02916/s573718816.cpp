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
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  ll ans=0;

  rep(i,n){
    ans+=b[i];
  }

  rep(i,n-1){
    if(a[i]+1==a[i+1]) ans+=c[a[i]-1];
  }
  cout << ans << endl;

  return 0;
}
