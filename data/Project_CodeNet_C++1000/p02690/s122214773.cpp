#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;
    cin >> x;
    map<ll, int> cek;
    for (ll i = 0; i * i * i * i * i <= INF; i++) {
        ll pw = i * i * i * i * i;
        cek[pw] = i;
        cek[-pw] = -i;
    }
    for (auto p: cek) {
        if (cek.count(x + p.fi)) {
            cout << cek[x + p.fi] << ' ' << p.se << '\n';
            exit(0);
        }
    }
    return 0;
}