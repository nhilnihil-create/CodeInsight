#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i, n)cin >> a[i];
    rep(i, n)cin >> f[i];
    sort(all(a)); sort(rall(f));
    ll ng = 0, ok = inf;
    while(ok-ng > 1){
        ll mid = (ok + ng) / 2;
        ll cnt = 0;
        rep(i, n){
            if(mid <= a[i]*f[i]){
                ll now = a[i]*f[i]-mid;
                cnt += (now+f[i]-1)/f[i];
            }
        }
        if(cnt <= k)ok = mid;
        else ng = mid;
    }
    if(accumulate(all(a), 0LL) <= k)cout << 0 << endl;
    else cout << ok << endl;
}
