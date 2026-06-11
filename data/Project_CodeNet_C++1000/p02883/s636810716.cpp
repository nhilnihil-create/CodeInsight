#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];

    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    ll l = -1;
    ll r = a[n-1]*f[0]+2;
    while (r-l>1) {
        ll x = (l+r)/2;
        //cout << l << " " << x << " " << r << endl;
        ll ik = 0;
        rep(i, n) {
            ll v = x/f[i];
            if (v<a[i]) ik += (a[i]-v);
        }
        if (ik>k) l = x;
        else r = x;
    }

    
    
    
    cout << r << endl;
    return 0;
}
