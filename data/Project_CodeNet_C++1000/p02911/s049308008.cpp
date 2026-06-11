#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
#define len(array) (sizeof(array)/sizeof(array[0]))
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k, q;
    cin >> n >> k >> q;
    ll point[n]= {0};
    rep (i, q) {
        int a;
        cin >> a;
        point[a-1]++;
    }
    rep (i, len(point)) {
        if ((k+point[i]-q) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}