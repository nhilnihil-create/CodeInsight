#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//using mint = modint1000000007;
//using mint = modint998244353;
//const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int n,m;
int main(){
    cin>>n>>m;
    dsu d(n);
    rep(i,m){
      int a,b;
      cin>>a>>b;
      --a;--b;
      d.merge(a,b);
    }
    int ans=d.groups().size()-1;
    cout<<ans<<endl;
    return 0;
}