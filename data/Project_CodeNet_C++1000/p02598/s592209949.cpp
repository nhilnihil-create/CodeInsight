#include <bits/stdc++.h>
#define maxN 200005
#define inf (int) 1e9 + 50
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

int n, k;
int a[maxN];

void enter() {
    cin >> n >> k;
    FOR(i, 1, n)
       cin >> a[i];
    sort(a + 1, a + n + 1);
}

bool ok(int x) {
    int ans = 0;
    FOR(i, 1, n) {
        int y = a[i], u = y / x;
        while(1ll * x * u < y) u++;
        ans += u - 1;
    }
    return ans <= k;
}

void solve() {
    int lo = 0, hi = inf;
    while(hi - lo > 1) {
        int m = (hi + lo)/2;
        if(ok(m)) hi = m;
        else lo = m;
    }
    cout << hi;
}

int main() {
    //freopen("main.inp", "r", stdin);
    enter();
    solve();
}
