#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 107;
int D[N], L[N];
signed main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> L[i];
    D[1] = 0;
    int ans = 1;
    for (int i = 2; i <= n + 1; ++i) {
        D[i] = D[i - 1] + L[i - 1];
        if (D[i] <= x) ++ans;
    }
    cout << ans;
}