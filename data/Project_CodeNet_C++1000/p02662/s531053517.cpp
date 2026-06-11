#include <bits/stdc++.h>

using namespace std;
const int maxn = 3005;
const int base = 998244353;
int n, s;
int a[maxn];
long long f[maxn][maxn + maxn];
// long long calc(int i, int s) {
//     if (s < 0) return 
// }
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    f[0][0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < a[i]; ++j)
            f[i][j] = f[i - 1][j] * 2 % base;
        for (int j = 0; j <= sum; ++j) 
            f[i][j + a[i]] = (f[i - 1][j] + f[i - 1][j + a[i]] * 2) % base; //classic
        sum += a[i];
        sum = min(sum, s);
    }
    cout << f[n][s];
    return 0;
}