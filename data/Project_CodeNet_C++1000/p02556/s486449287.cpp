#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        a[i]=x+y;
        b[i]=x-y;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=max(abs(a[0]-a[n-1]),abs(b[0]-b[n-1]));
    cout<<ans<<endl;
    return 0;
}