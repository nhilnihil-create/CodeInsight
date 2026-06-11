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
const int mod = 1e9 + 7;

bool check(ll n, ll k) {
    while (n % k == 0) n /= k;
    return (n % k == 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    int ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        if (check(n, i)) ans++;
        if (i * i != n && check(n, n / i)) ans++;
    }
    if (n > 2) ans++;
    n--;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        if (i * i == n) ans++;
        else ans += 2;
    }
    cout << ans;
    return 0;
}
