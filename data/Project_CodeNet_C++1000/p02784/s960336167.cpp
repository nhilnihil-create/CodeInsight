#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
    io;
    ll h, n;
    cin >> h >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.rbegin(), v.rend());
    rep(i,n) {
        h -= v[i];
        if (h <= 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
