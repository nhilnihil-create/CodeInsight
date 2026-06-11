#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = (n / (a + b)) * a;
    ll kek = n % (a + b);
    cout << ans + min(kek, a);
    return 0;
}
