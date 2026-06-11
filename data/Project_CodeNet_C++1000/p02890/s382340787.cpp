#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int c[n+1];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    sort(c, c+n+1);

    int ps[n+1];
    for (int i = 0; i <= n; i++) {
        ps[i] = i == 0 ? 0 : ps[i-1] + c[i];
    }

    for (int i = 1; i <= n; i++) {
        int l = -1, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;

            int t = upper_bound(c, c + n + 1, mid) - c;
            if (ps[t-1] + 1ll * (n + 1 - t) * mid >= 1ll * i * mid) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << l << "\n";
    }

    return 0;
}
