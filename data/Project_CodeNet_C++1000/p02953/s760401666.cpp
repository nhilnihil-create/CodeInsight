#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n,0);
    rep(i,n) cin >> h[i];
    bool ok = true;
    for (int i = n-1; i > 0; i--) {
        if (h[i]+1 == h[i-1]) h[i-1] -= 1;
        else if (h[i]+1 < h[i-1]) ok = false;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
