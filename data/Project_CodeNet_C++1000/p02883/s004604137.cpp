#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i, n)cin >> a[i];
    rep(i, n)cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
    ll l = -1;
    ll r = (ll)1e12 + 1;
    while(l + 1 < r){
        ll x = (l + r) / 2;
        ll cnt = 0;
        rep(i, n){
            if(a[i] > x / f[i]){
                cnt += a[i] - x / f[i];
            }
        }
        if(cnt <= k)r = x;
        else l = x;
    }
    cout << r << endl;
}