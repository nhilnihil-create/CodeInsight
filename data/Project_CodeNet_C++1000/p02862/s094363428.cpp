#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int mpow(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b % 2) c = c*a%MOD;
        b/=2;
        a = a*a%MOD;
    }
    return c;
}

int C (ll a, ll b) {
    ll nume = 1;
    for (int i = a; i > a-b; i--) {
        nume = nume*i%MOD;
    }
    ll deno = 1;
    for (int i = 2; i <= b; i++) {
        deno = deno*i%MOD;
    }
    return nume*mpow(deno, MOD-2) % MOD;
}

int main() {
    int x, y;
    cin >> x >> y;
    int a = (x+y)/3;
    int b = x-a;
    int c = y-a;
    if ((x+y)%3 != 0 || b < 0 || c < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << C(b+c, b) << endl;
    return 0;
}
