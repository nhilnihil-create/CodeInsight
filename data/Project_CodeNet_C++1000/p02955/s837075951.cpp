#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll all = 0;
    rep(i,n) all += a[i];
    vector<ll> d;
    for(ll i=1;i*i<=all;i++){
        if(all%i==0){
            d.push_back(i);
            d.push_back(all/i);
        }
    }

    ll ans = 1;
    for(ll t:d){
        vector<ll> rem(n);
        rep(i,n) rem[i] = a[i]%t;
        sort(rem.begin(),rem.end());
        vector<ll> cum(n);
        rep(i,n) cum[i] = t - rem[i];
        for(ll i=n-2;i>=0;i--) cum[i] += cum[i+1];
        ll now = 0;
        ll res = max(now,cum[0]);
        rep(i,n-1){
            now += rem[i];
            res = min(res,max(now,cum[i+1]));
        }
        now += rem[n-1];
        res = min(res,max(now,0LL));
        if(res <= k) ans = max(ans,t);
    }

    cout << ans << endl;
    return 0;
}