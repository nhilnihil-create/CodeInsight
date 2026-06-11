#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100055];
long long suff[100055];

int main() {
    cin >> n;

    for (int i = 0; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    if (a[0] > 1 || (a[0] == 1 && n != 0)) {
        puts("-1");
        return 0;
    }

    for (int i = n; i >= 0; i--) {
        suff[i] = a[i] + suff[i + 1];
    }

    long long cur = 1;
    long long res = 1;

    for (int i = 1; i <= n; i++) {
        long long can = min(cur * 2, suff[i]);

        res += can;
        cur = can - a[i];

        if (cur < 0) {
            puts("-1");
            return 0;
        }
    }

    cout << res;

    return 0;
}
