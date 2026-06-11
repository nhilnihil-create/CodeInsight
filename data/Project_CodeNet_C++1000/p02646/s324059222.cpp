#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    bool ok = true;
    if(v <= w) ok = false;
    else if((llabs(b-a) + (v - w) - 1) / (v - w) > t) ok = false;
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
