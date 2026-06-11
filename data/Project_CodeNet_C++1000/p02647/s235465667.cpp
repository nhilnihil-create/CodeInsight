#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], n, k;

bool change() {
    static int d[N];
    for (int i = 1; i <= n; i++) d[i] = 0;
    for (int i = 1; i <= n; ++i) {
        ++d[max(1, i - a[i])];
        --d[min(n + 1, i + a[i] + 1)];
    }
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
        a[i] = d[i];
    }
    for (int i = 1; i <= n; ++i) if (a[i] < n) return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (k && change()) --k;
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}