#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

const int MAXN = 105000;

int n;
int a[MAXN];
long long sum[MAXN];

int main() {

    scanf("%d", &n);
    for (int i = 0; i <= n; i++) 
        scanf("%d", &a[i]);

    sum[n] = a[n];
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i];

    long long ans = 0;
    long long nxtLevel = 1;

    for (int i = 0; i <= n; i++) {
        ans += nxtLevel;
        if (nxtLevel < a[i]) {
            puts("-1");
            return 0;
        }
        nxtLevel -= a[i];

        if (i == n) {
            if (nxtLevel != 0) {
                puts("-1");
                return 0;
            } else
                break;
        }

        long long leaves = sum[i + 1];
        nxtLevel = min(2 * nxtLevel, leaves);
    }

    cout << ans << endl;

    return 0;
}
