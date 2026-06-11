#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    ll n; cin >> n;
    ll sum = 0;
    FOR(i, 1, n)
        sum += (2 + n - i) * (n - i + 1) / 2;
    FOR(i, 1, n - 1) {
        ll u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        sum -= u * (n - v + 1);
    }
    cout << sum << endl;
}