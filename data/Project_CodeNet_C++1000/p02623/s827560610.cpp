#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int n, m;
long long k, a[N + 1], b[N + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j + 1];
        b[j + 1] += b[j];
    }
    int res = 0;
    for (int i = 0, j = m; i <= n; ++i) {
        if (a[i] > k)
            break;
        while (a[i] + b[j] > k)
              --j;
        res = max(i + j, res);

    }
    cout << res << endl;
}
