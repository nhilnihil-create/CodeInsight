#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    ll sum1 = 0;
    rep(i, n + 1) {
        cin >> a[i];
        sum1 += a[i];
    }
    rep(i, n) cin >> b[i];

    rep(i, n){
        if (b[i] <= a[i]) a[i] -= b[i]; 
        else  if (b[i] <= a[i] + a[i + 1]) {
            a[i + 1] -= b[i] - a[i];
            a[i] = 0;
        }
        else {
            a[i] = 0;
            a[i + 1] = 0;
        }
    }

    ll sum2 = 0;
    rep(i, n + 1) sum2 += a[i];
    cout << sum1 - sum2;


}
