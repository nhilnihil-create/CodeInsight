#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a[100100], total, l, r, put2[30], lim_l[100100], lim_r[100100], maxx[100100];

ll calc_lim_r(int index) {
    if (index <= 27)
        return min(put2[index], a[index] + maxx[index + 1]);
    return a[index] + maxx[index + 1];
}

int main() {
    put2[0] = 1;
    for (int i = 1; i <= 27; i++)
        put2[i] = put2[i - 1] * 2;
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    maxx[n] = a[n];
    for (int i = n - 1; i >= 0; i--)
        maxx[i] = maxx[i + 1] + a[i];

    l = r = a[n];
    lim_l[n] = l;
    lim_r[n] = r;

    if (l > calc_lim_r(n)) { /// prea multe noduri finale
        cout << -1;
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        l = (l + 1) / 2 + a[i];
        r += a[i];
        r = min(r, calc_lim_r(i));

        if (l > r || l <= 0) {
            cout << -1;
            return 0;
        }

        lim_l[i] = l;
        lim_r[i] = r;
    }

    ll act = 1;
    for (int i = 0; i <= n; i++) {
        if (!(lim_l[i] <= act && act <= lim_r[i])) {
            cout << -1;
            return 0;
        }
        total += act;
        act = min((act - a[i]) * 2, lim_r[i + 1]);
    }

    cout << total;
    return 0;
}
