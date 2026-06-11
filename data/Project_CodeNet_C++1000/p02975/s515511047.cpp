#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

int a[maxn];
int cnt[32];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0, x = a[i]; j < 32; j++, x /= 2)
            cnt[j] += x % 2;
    }
    vector<bool> reg(32, 0);
    int cc = 0;
    for (int j = 31; j >= 0; j--) {
        if (cnt[j] && (n % 3 || cnt[j] != 2 * n / 3)) {
            cout << "No";
            return 0;
        }
        reg[j] = (cnt[j] > 0);
        cc += reg[j];
    }
    if (cc == 0) {
        cout << "Yes";
        return 0;
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    if (mp.size() > 3 || mp.size() == 1) {
        cout << "No";
        return 0;
    }
    vector<pi> cv;
    for (auto gg : mp)
        cv.pb(gg);
    if (cv.size() == 2) {
        if (cv[0].r != n / 3 &&
            cv[1].r != n / 3) {
            cout << "No";
            return 0;
        }
        int x = (cv[0].r == n / 3 ? cv[1].l : cv[0].l);
        int y = (cv[0].l == x ? cv[1].l : cv[0].l);
        int cx = x;
        for (int i = 0; i < 32; i++, cx /= 2) {
            if (!reg[i]) continue;
            if (cx % 2 == 0) {
                cout << "No";
                return 0;
            }
        }
        if (y) {
            cout << "No";
            return 0;
        }
    } else {
        if (cv[0].r != n / 3 ||
            cv[1].r != n / 3) {
                cout << "No";
                return 0;
            }
        int x = cv[0].l, y = cv[1].l, z = cv[2].l;
        bool fg = 1;
        for (int i = 0; i < 32; i++, x /= 2, y /= 2, z /= 2) {
            if (!reg[i]) continue;
            if ((x % 2 == 0) + (y % 2 == 0) + (z % 2 == 0) != 1) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
