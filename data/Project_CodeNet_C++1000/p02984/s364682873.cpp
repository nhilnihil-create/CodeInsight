#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k = 1, b = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        a[i] *= 2;
        k = k * (-1), b = a[i] - b;
    }
    a[n] *= 2;
    int x = (a[n] - b) / 2;
    k = 1, b = 0;
    for (int i = 1; i <= n; ++i) {
        cout << k * x + b << " ";
        k = k * (-1), b = a[i] - b;
    }
    return 0;
}

