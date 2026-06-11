#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1), b(n);
    rep1(i, n+1) cin >> a[i];
    rep1(i, n) cin >> b[i];
    ll ans = 0, cnt = 0;
    rep1(i, n){
        ans += min(a[i], b[i]);
        b[i] -= a[i];
        if (b[i] < 0) b[i] = 0;
        ans += min(a[i+1], b[i]);
        a[i+1] -= b[i];
        if (a[i+1] < 0) a[i+1] = 0;
    }
    cout << ans << endl;
}