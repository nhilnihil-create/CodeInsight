#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
vector<ll> a;
vector<ll> f;
int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll a1;
        cin >> a1;
        a.push_back(a1);
    }
    for (int i = 0; i < n; i++) {
        ll a2;
        cin >> a2;
        f.push_back(a2);
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(f.begin(), f.end());
    ll m = -1;
    ll M = 1000000000001;
    while (M - m > 1) {
        ll med = (M + m) / 2;
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > med / f[i]) {
                count += a[i] - med / f[i];
            }
        }
        if (k < count) {
            m = med;
        }
        else {
            M = med;
        }
    }
    cout << M << endl;
    return 0;
}