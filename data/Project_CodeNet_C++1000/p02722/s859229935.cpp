#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<ll> div(ll a) {
    vector<ll> ret;
    if (a >= 2) ret.push_back(a);
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ret.push_back(i);
            if (i * i != a) ret.push_back(a / i);
        }
    }
    return ret;
}
/* function */
/* main */
int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    vector<ll> c = div(N-1);
    ans += c.size();

    vector<ll> v = div(N);
    for (ll d : v) {
        ll tmp = N;
        while (tmp % d == 0) tmp /= d;
        if (tmp % d == 1) ans++;
    }
    cout << ans << '\n';
}
