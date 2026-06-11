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
    int n; cin >> n;
    vi a(n + 2), ps(n + 2);
    FOR(i, 1, n) {
        cin >> a[i];
        ps[i] = ps[i - 1] ^ a[i];
    }
    FOR(i, 1, n)
        cout << (ps[n] ^ a[i]) << ' ';
    cout << '\n';
}