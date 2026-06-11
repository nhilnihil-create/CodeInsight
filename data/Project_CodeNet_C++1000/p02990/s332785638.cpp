#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7, N = 2005;

int C[N][N];

int get(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return n == 0;
    return C[n - 1][k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int kek = (get(n - k, i - 1) + get(n - k, i + 1)) % M;
        kek += get(n - k, i) * 2;
        kek %= M;
        cout << kek * get(k, i) % M << '\n';
    }
    return 0;
}
