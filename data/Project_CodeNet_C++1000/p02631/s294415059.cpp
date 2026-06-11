#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    ll allxor = 0;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        allxor ^= a[i];
    }
    rep(i, n) {
        cout << ll(allxor ^ a[i]) << " ";
    }
    cout << endl;
}
