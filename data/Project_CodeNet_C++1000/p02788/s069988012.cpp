
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, d, a;
ii xh[N];
int x, h;
ll cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d >> a;
    for (int i = 0; i < n; ++i) {
        cin >> x >> h;
        xh[i] = ii(x, h);
    }
    sort(xh, xh + n);

    ll c = 0; // current damage
    int p = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        c += cnt[i]; // pre damage
        int health = xh[i].second;
        if (health > c) {
            int need = (health - c + a - 1) / a; // need additional x bombs.
            res += need;
            ll x = 1LL * need * a; // deal x more damage
            c += x;
            // maintain sliding window's right pointer
            while (p < n && xh[p].first - xh[i].first <= d * 2) ++p;
            cnt[p] -= x; // reduce damage if moves out of current window.
        }
    }

    cout << res << endl;

    return 0;
}

