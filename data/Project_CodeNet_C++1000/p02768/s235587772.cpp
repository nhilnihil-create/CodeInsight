#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define rep(i, n) for (int i = 0; i < (n); ++i)

static ll m = 1e9+7;

int main() {

    ll n, a, b;
    cin >> n >> a >> b;

    vl v(40);
    v[0] = 2;
    for (int i = 0; i < 32; ++i) {
        v[i+1] = v[i] * v[i] % m;
    }

    ll sum = 1;
    rep(i, 32) {
        if(n>>i&1) {
            // cout << (n>>i)<< endl;
            sum *= v[i];
            sum %= m;
            // cout << i << " " << sum << endl;
        }
    }

    if (sum == 0) sum += (m - 1);
    else sum--;

    vector<ll> modinv(2e5+9);
    modinv[1] = 1;
    for (int i = 2; i <= 2e5+3; i++) {
        modinv[i] = modinv[m%i] * (m-m/i) % m;
    }

    ll sum_a = 1;
    ll sum_b = 1;
    ll tmp = n;
    rep(i, a) {
        sum_a *= tmp;
        sum_a %= m;
        sum_a *= modinv[i+1];
        sum_a %= m;
        tmp--;
    }

    tmp = n;
    rep(i, b) {
        sum_b *= tmp;
        sum_b %= m;
        sum_b *= modinv[i+1];
        sum_b %= m;
        tmp--;
    }

    cout << (sum + 2 * m - sum_a - sum_b) % m << endl;

    return 0;
}
