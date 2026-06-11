// Leviathan-R
#include <bits/stdc++.h>
#define maxN 200005
#define inf (int) 1e9
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

int n;
char a[maxN];
int s[maxN];

void enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n)
       s[i] = s[i - 1] + (a[i] == 'R');
}

void solve() {
    int S = 0, ans = inf;
    REP(i, n, 1) S += (a[i] == 'R') ? 1 : 0;
    ans = min(S, n - S);
    FOR(i, 1, S) {
        int res = 0;
        res += i - s[i] + S - i;
        ans = min(ans, res);
    }
    cout << ans;
}

int main() {
    //freopen("main.inp", "r", stdin);
    enter();
    solve();
}
