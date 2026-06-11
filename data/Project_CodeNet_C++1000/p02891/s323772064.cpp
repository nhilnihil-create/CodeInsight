#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e6;

ll n, m, k, t;

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    string s;
    cin >> s;
    cin >> k;
    n = s.length();
    bool f = 0;
    bool f1 = 0;
    ll cnt1 = 0, cnt2 = 0;
    ll dans = 0;
    ll cur = 1;
    for (q = 1; q < n; q++) {
        if (s[q] == s[q - 1]) {
            cur++;
        }
        else {
            if (!f) {
                f1 = cur % 2;
            }
            f = 1;
            dans += cur / 2;
            cur = 1;
        }
    }
    if (!f) {
        cout << n * k / 2;
        return 0;
    }
    dans += cur / 2;
    ll ans = dans * k;
    if (s[n - 1] == s[0] && cur % 2 == 1 && f1) {
        ans += k - 1;
    }
    cout << ans;
    return 0;
}
