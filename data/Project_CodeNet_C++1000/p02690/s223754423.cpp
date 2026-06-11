#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> makeDivisors(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            ret.push_back(i);
            if(i*i != n) ret.push_back(n/i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

ll cal(ll a, ll b) {
    return pow(a, 5LL) - pow(b, 5LL);
}

int main() {
    // (A - B) (A^4 + A^3 B + A^2 B^2 + A B^3 + B^4)
    // どちらかはプラスなのでAをプラスとする
    ll X;
    cin >> X;
    vector<ll> divs = makeDivisors(X);
    for (ll a = 0; a < 100000; a++) {
        for (ll d : divs) {
            ll b = a - d;
            if (cal(a, b) == X) {
                printf("%ld %ld\n", a, b);
                return 0;
            }
        }
    }
}