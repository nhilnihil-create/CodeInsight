#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

    ll sum = a[p - 1];

    int ans = p;
    for (int i = p; i < n; i++) {
        if (a[i] + m >= a[p - 1]) {
            if ((p - 1 + n - i >= v) || (sum + m * (v - p + 1 - n + i) <= (a[i] + m) * (i - p + 1))) ans++;
        }
        sum += a[i];
    }
    cout << ans;
}