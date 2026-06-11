#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n; cin >> n;
    vector<ll> xvec(n, 0);
    vector<ll> yvec(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> xvec[i] >> yvec[i];
    }

    vector<ll> xy0;
    vector<ll> xy1;
    for(int i = 0; i < n; ++i) {
        xy0.emplace_back(xvec[i]-yvec[i]);
        xy1.emplace_back(xvec[i]+yvec[i]);
    }

    sort(xy0.begin(), xy0.end());
    sort(xy1.begin(), xy1.end());
    ll ans = max((xy0[n-1]-xy0[0]), (xy1[n-1]-xy1[0]));
    cout << ans << endl;
}