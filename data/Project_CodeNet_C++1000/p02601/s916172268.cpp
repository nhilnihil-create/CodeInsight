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
    int a, b, c; cin >> a >> b >> c;
    int k; cin >> k;
    int x = 0;
    while (a >= b) b *= 2, x++;
    while (b >= c) c *= 2, x++;
    if (x <= k) cout << "Yes\n";
    else cout << "No\n";
}