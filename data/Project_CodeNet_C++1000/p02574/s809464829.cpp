#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, a[N], cnt[N];
long long dp[N];

int gcd (int x, int y) {
    int r = 0;
    while (y != 0) {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;

    int g = 0;
    for (int i = 1; i <= n; i++) g = gcd(g, a[i]);
    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }

    for (int i = N - 1; i >= 1; i--) {
        dp[i] = 1LL * cnt[i] * (cnt[i] - 1) / 2;
        for (int j = i + i; j < N; j += i) {
            dp[i] -= dp[j];
        }
    }

    if (dp[1] == 1LL * n * (n - 1) / 2) cout << "pairwise coprime" << endl;
    else if (g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}
