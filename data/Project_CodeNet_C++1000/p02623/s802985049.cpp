#include <algorithm>
#include <cmath>
#include <cstring>  // memset()
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define For(i, a, b) for (int i = (int)(a), sz = (int)(b); i < sz; i++)
#define rFor(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

const int MAX = 1e5 + 5;

int main() {
    IO;
    ll n, m, k, c = 0, ans = 0, x = 0, y = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    For(i, 0, n) cin >> a[i];
    For(i, 0, m) cin >> b[i];
    For(i, 0, n) {
        if (c + a[i] <= k)
            c += a[i];
        else
            break;
        x++;
    }
    ans = y = x--;
    For(i, 0, m) {
        while (x >= 0 && c + b[i] > k)
            c -= a[x--], y--;
        if (c + b[i] <= k)
            c += b[i], y++;
        else
            break;
        ans = max(ans, y);
    }
    printf("%lld\n", ans);
    return 0;
}