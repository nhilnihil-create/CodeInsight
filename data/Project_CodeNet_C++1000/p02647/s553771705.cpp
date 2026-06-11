#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    k = min(k, 100);
    while (k--) {
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            b[max(0, i - a[i])]++;
            b[min(n, i + a[i] + 1)]--;
        }
        for (int i = 0; i < n; i++) b[i + 1] += b[i];
        for (int i = 0; i < n; i++) a[i] = b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
