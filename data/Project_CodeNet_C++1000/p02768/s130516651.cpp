#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
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


int modpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % inf;
        y >>= 1;
        x = 1LL * x * x % inf;
    }
    return res;
}
 
int comb(int n, int k) {
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = 1LL * ans * (n+ 1 - i) % inf;  // *=n!/(n-k)!
        ans = 1ll *ans * modpow(i, inf - 2) % inf;// *=inv k!
    }
 
    return ans;
}
int main(){
  int n,a,b;
  cin>>n>>a>>b;
 // cout<<comb(n,3)<<endl;
 int ans=modpow(2,n)-1-comb(n,a)-comb(n,b);
  if(ans<=0)ans+=inf;
  if(ans<=0)ans+=inf;
  if(n==2)ans=0;
  cout<<ans<<endl;
}