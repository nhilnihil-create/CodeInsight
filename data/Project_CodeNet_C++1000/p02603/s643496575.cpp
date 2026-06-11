#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vll a(n);
    FOR(i, 0, n - 1)
        cin >> a[i];
    ll m = 1000;
    FOR(i, 1, n - 1) {
        if (a[i] > a[i - 1]) {
            ll c = m / a[i - 1];
            m = m - a[i - 1] * c + a[i] * c;
        }
    }
    cout << m << endl;
}