#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    if ((a + b) % 2 == 0) {
        cout << abs(b - a) / 2;
        return 0;
    }
    if (a > b) swap(a, b);
    int c = a, d = b;
    b -= a;
    int ans = a + (b - 1) / 2;
    c += (n - d);
    ans = min(ans, (n - d) + 1 + (n - c) / 2);
    cout << ans;
    return 0;
}
