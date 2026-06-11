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
    int x; cin >> x;
    FOR(i, -118, 119) FOR(j, -119, 118) {
        ll a = i, b = j;
        if (a*a*a*a*a - b*b*b*b*b == x)
            return cout << a << ' ' << b << endl, 0;
    }
}