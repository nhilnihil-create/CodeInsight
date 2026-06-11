#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
#define ld long double
 
using namespace std;
 
 
const int N = 4e5 + 123;
const int MAXN = 1e5 + 12;
const int inf = 1e9 + 7;
const ll mod = 1e9 + 7;


ll n, b[N], p[N];
char a[N];

 
int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    if (a[1] == 'W')
        return cout << 0, 0;
    b[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        if (a[i] != a[i - 1])
            b[i] = b[i - 1];
        else
            b[i] = 1 - b[i - 1];
    }
    for (int i = 1; i <= 2 * n; i++)
        p[i] = p[i - 1] + b[i];
    if (p[2 * n] != n)
        return cout << 0, 0;
    ll ans = 1;
    for (ll i = 1; i <= 2 * n; i++) {
        if (b[i] == 0)
            ans = (ans * (p[i] - (i - 1 - p[i]))) % mod;
    }
    for (ll i = 1; i <= n; i++)
        ans = (ans * i) % mod;
    cout << ans;
    return 0;
}