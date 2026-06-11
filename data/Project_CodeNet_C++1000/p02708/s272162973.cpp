#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
ll n,k;
  cin>>n>>k;
  ll ans=0;
  rep(i,k,n+2){
    ans+=(i*(2*n-i+1)/2)-(i*(i-1)/2)+1;
   // cout<<(i*(2*n-i+1)/2)<<" "<<(i*(i-1)/2)<<endl;
      ans%=inf;
  }
  cout<<ans<<endl;
}






//ガンバる