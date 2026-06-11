#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
#define ld long double
 
using namespace std;
 
 
const int N = 2e5 + 123;
const int MAXN = 1e5 + 12;
const int inf = 1e9 + 7;
const ll mod = 1e9 + 7;


ll n, a[N], mx[21][N], len[N], pw[30], Lmx[N], Lmn[N], Rmx[N], Rmn[N];


ll get(ll l, ll r) {
    ll ln = r - l + 1;
    ll x = len[ln];
    return max(mx[x][l], mx[x][r + 1 - pw[x]]);
}

 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx[0][i] = a[i];
        Lmx[i] = 0;
        Rmn[i] = n + 1;
    }
    ll t = 1;
    for (int i = 0; i <= 20; i++) {
        pw[i] = t;
        t *= 2;
    }
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        while (pw[cur + 1] <= i)
            cur++;
        len[i] = cur;
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (pw[j] + i - 1 > n)
                break;
            mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + pw[j - 1]]);    
        }
    }
    for (int i = 1; i <= n; i++) {
        ll L, R, M;
        L = 1, R = i - 1;
        while (L <= R) {
            M = (L + R) / 2;
            if (get(M, i) == a[i])
                R = M - 1;
            else {
                Lmx[i] = max(Lmx[i], M);
                L = M + 1;
            }
        }
        if (Lmx[i] == 0)
            continue;
        Lmn[i] = Lmx[i];
        L = 1; R = Lmx[i] - 1;
        while (L <= R) {
            M = (L + R) / 2;
            if (get(M, Lmx[i] - 1) < a[i]) {
                Lmn[i] = min(Lmn[i], M);
                R = M - 1;
            } else
                L = M + 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        ll L, R, M;
        L = i + 1, R = n;
        while (L <= R) {
            M = (L + R) / 2;
            if (get(i, M) == a[i])
                L = M + 1;
            else {
                Rmn[i] = min(Rmn[i], M);
                R = M - 1;
            }
        }
        if (Rmn[i] == n + 1)
            continue;
        L = Rmn[i] + 1; R = n;
        Rmx[i] = Rmn[i];
        while (L <= R) {
            M = (L + R) / 2;
            if (get(Rmn[i] + 1, M) < a[i]) {
                Rmx[i] = max(Rmx[i], M);
                L = M + 1;
            } else
                R = M - 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (Lmx[i] != 0)
            ans += a[i] * (Lmx[i] - Lmn[i] + 1) * (Rmn[i] - i);
        if (Rmn[i] != n + 1)
            ans += a[i] * (Rmx[i] - Rmn[i] + 1) * (i - Lmx[i]);
    }
    cout << ans;
    return 0;
}