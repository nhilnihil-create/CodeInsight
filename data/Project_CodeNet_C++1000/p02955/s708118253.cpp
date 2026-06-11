#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    set<ll> cand;
    for(ll i = 1; i*i <= sum; i++){
        if(sum%i == 0){
            cand.insert(i);
            cand.insert(sum/i);
        }
    }
    ll ans = 1;
    for(ll x : cand){
        ll need = 0;
        vector<ll> r(n);
        rep(i,n) r[i] = a[i] % x;
        sort(r.begin(), r.end());
        ll tot = 0;
        rep(i,n) tot += r[i];
        ll l = n - tot/x;
        rep(i,l) need += r[i];
        if(need <= k) chmax(ans, x);
    }
    cout << ans << endl;
    return 0;
}