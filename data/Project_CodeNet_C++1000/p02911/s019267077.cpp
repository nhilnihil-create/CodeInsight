#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    ll n,k,q; cin >> n >> k >> q;
    ll a[n]; rep(i,n) a[i] = -q+k;
    ll ind;
    rep(i,q) {
        cin >> ind;
        a[ind-1]++;
    }
    rep(i,n) {
        if (a[i] > 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
