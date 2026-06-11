#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, q;
    cin >> k >> q;
    int d[k];
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }

    while (q--) {
        int n, x, m;
        cin >> n >> x >> m;
        x %= m;

        ll psd[k+1], cnt[k+1];
        for (int i = 0; i <= k; i++) {
            psd[i] = i == 0 ? 0 : psd[i-1] + d[i-1] % m;
            cnt[i] = i == 0 ? 0 : cnt[i-1] + (d[i-1] % m == 0);
        }

        ll an = x + (n - 1) / k * psd[k] + psd[(n-1)%k];
        int c0 = (n - 1) / k * cnt[k] + cnt[(n-1)%k];

        cout << n - 1 - an / m - c0 << endl;
    }

    return 0;
}
