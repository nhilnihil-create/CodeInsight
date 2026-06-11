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
    int n, p;
    cin >> n >> p;
    vector<ll> my_pow(n + 1);
    my_pow[0] = 1;
    for (int i = 1; i <= n; i++) my_pow[i] = (my_pow[i - 1] * 10) % p;
    string s;
    cin >> s;
    if (p == 2 || p == 5) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0) ans += (i + 1);
        }
        cout << ans;
        return 0;
    }
    vector<int> cnt(p);
    cnt[0]++;
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cur *= 10;
        cur += s[i] - '0';
        cur %= p;
        ans += cnt[(cur * my_pow[n - i - 1]) % p];
        cnt[(cur * my_pow[n - i - 1]) % p]++;
    }
    cout << ans;
    return 0;
}
