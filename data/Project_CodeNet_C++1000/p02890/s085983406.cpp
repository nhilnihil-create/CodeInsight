#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int>
#define ll long long
#define X first
#define Y second

const int N = 3E5 + 10;

int n, m;
ll a[N], Sum[N], d[N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

bool check(int mid, int k)
{
    int pos = upper_bound(a + 1, a + 1 + m, mid) - (a + 1);
    if (pos > m) pos = m;
    if (Sum[pos] / mid + (m - pos) >= k) return true;
    return false;
}

void Solve()
{
    for (int i = 1; i <= n; i++) d[a[i]]++;
    for (int i = 1; i <= n; i++) if (d[i] > 0) a[++m] = d[i];
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++) Sum[i] = Sum[i - 1] + a[i];

    for (int k = 1; k <= n; k++) {
        int l = 1, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid, k)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}

