#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll ok = 1e18, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        ll cost = 0;
        rep(i,n){
            ll add = (a[i]*f[i] - mid + f[i] - 1) / f[i];
            chmax(add, 0LL);
            cost += add;
        }
        if(cost <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
