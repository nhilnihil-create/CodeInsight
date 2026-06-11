#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll l = -1, r = 1e12;
    while (l+1 < r) {
        ll c = (l+r)/2;
        ll s = 0;
        rep(i,n) {
            s += max(ll(0), a[i]-c/f[i]);
        }
        if (s <= k) r = c;
        else l = c;
    }
    cout << r << endl;
    return 0;
}