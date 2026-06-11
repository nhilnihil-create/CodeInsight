#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int a[200005];

int main() {
    int n, k;
    cin >> n >> k;

    rep(i, n) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }

    int sum = 0;
    for (int i = k; i <= n; i++) sum = max(sum, a[i] - a[i - k]);

    printf("%.12f\n", (sum + k) / 2.0);
    return 0;
}
