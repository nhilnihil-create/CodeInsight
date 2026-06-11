#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
/* global variables */
/* function */
vector<pll> factorPair(ll x) {
    vector<pll> ret;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0)
            ret.push_back(pll(i, x / i));
    }
    return ret;
}
/* main */
int main(){
    ll N;
    cin >> N;
    vector<pll> factors = factorPair(N);
    ll ans = LINF;
    for (pll f : factors) {
        ans = min(ans, f.first + f.second - 2);
    }
    cout << ans << '\n';
}
