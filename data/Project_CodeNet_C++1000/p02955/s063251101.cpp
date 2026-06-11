#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
 
 
using namespace std;
 
 
const int N = 4e3 + 219;
const ll M = 3e5 + 19;
const ll inf = 1e15 + 10;
const ll mod = 1e9 + 7;
 
 
ll n, k, a[N], r[N], p[N], s[N], ans = 0; 
vector <ll> d; 
 
 
int main() {
    cin >> n >> k;
    ll S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    ll t = sqrt(S + 0.5);
    for (ll i = 1; i <= t; i++) {
        if (S % i == 0) {
            d.pb(i);
            if (S / i != i)
                d.pb(S / i);
        }
    }
    for (int i = 0; i < d.size(); i++) {
        for (int j = 1; j <= n; j++)
            r[j] = a[j] % d[i];
        sort(r + 1, r + n + 1);
        p[0] = s[n + 1] = 0;
        for (int j = 1; j <= n; j++)
            p[j] = p[j - 1] + r[j];
        for (int j = n; j >= 1; j--) {
            if (r[j] == 0)
                s[j] = s[j + 1];
            else
                s[j] = s[j + 1] + d[i] - r[j];
        }
        bool is = 0;
        for (int j = 1; j < n; j++) {
            if ((p[j] - s[j + 1]) % d[i] == 0) {
                if (p[j] >= s[j + 1] && p[j] <= k) {
                    is = 1;
                    break;
                }
                if (p[j] < s[j + 1] && s[j + 1] <= k) {
                    is = 1;
                    break;
                }
            }
        }
        if (is)
            ans = max(ans, d[i]);
    }
    cout << ans;
}