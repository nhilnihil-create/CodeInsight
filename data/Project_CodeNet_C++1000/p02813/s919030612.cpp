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
    vi perm(n), p(n), q(n);
    FOR(i, 0, n - 1) cin >> p[i];
    FOR(i, 0, n - 1) cin >> q[i];
    FOR(i, 0, n - 1) perm[i] = i + 1;
    int a = 0, b = 0;
    vi tt(perm);
    do {
        a++;
        if (tt == p) break;
    } while (next_permutation(all(tt)));
    tt = perm;
    do {
        b++;
        if (tt == q) break;
    } while (next_permutation(all(tt)));
    cout << abs(a - b) << endl;
}