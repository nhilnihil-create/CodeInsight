#include <bits/stdc++.h>
#define int long long
#define double long double
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

int n, ans = 0;

int get(int x) {
    return (x * (x + 1)) / 2;
}

void analyze(int a, int b) {
    if (b > a) {
        ans += get(n - a);
    } else {
        ans += b * a - get(b);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        analyze(a, b);
        analyze(b, a);
    }
    for (int i = n; i >= 1; i--) {
        ans += (i * (2 - i));
    }
    cout << ans << '\n';

    fflush(stdout);
    return 0;
}
