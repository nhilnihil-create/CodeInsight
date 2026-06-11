#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n-1) cin >> b[i];
    ll ans = b[0];
    rep(i,n-2) ans += min(b[i], b[i+1]);
    ans += b[n-2];
    cout << ans << endl;
    return 0;
}
