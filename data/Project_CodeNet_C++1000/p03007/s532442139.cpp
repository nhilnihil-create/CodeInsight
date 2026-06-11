#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 2) {
        cout << a[1] - a[0] << endl;
        cout << a[1] << " " << a[0] << endl;
        return 0;
    }
    if (a[0] * a[n - 1] < 0) {
        int j = n - 1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0)
                j = min(j, i);
            ans += (a[i] < 0 ? -1 * a[i] : a[i]);
        }
        cout << ans << endl;
        int tmp = a[0];
        for (int i = j; i < n - 1; i++) {
            cout << tmp << " " << a[i] << endl;
            tmp -= a[i];
        }
        cout << a[n - 1] << " " << tmp << endl;
        tmp = a[n - 1] - tmp;
        for (int i = 1; i < j; i++) {
            cout << tmp << " " << a[i] << endl;
            tmp -= a[i];
        }
    } else {
        if (a[0] + a[n - 1] < 0) {
            reverse(a.begin(), a.end());
            int ans = a[0];
            for (int i = 1; i < n; i++) {
                ans -= a[i];
            }
            cout << ans << endl;
            int tmp = a[0];
            for (int i = 1; i < n; i++) {
                cout << tmp << " " << a[i] << endl;
                tmp -= a[i];
            }
        } else {
            int ans = -1 * a[0];
            for (int i = 1; i < n; i++) {
                ans += a[i];
            }
            cout << ans << endl;
            int tmp = a[0];
            for (int i = 1; i < n - 1; i++) {
                cout << tmp << " " << a[i] << endl;
                tmp -= a[i];
            }
            cout << a[n - 1] << " " << tmp << endl;
        }
    }

    return 0;
}
