#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    vector<ll>  cnt(1001010,0);
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<bool> ok(1000005,true);
  	ll x = 0;
    for(ll i = 0;i<1000001;i++){
      	x = i;
      	if(cnt[x] < 1)continue;
      	//ll x = a[i];
        if(cnt[x] > 1)ok[x] = false;
        for(ll i = 2*x;i < 1000001;i += x)ok[i]=false;
    }
    ll res = 0;
    rep(i,n)if(ok[a[i]])res++;
    cout << res << "\n";
    return 0;
}
