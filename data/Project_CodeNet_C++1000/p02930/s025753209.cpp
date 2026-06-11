#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int ans[505][505];

void solve(int L, int R, int level) {
    if (R - L <= 1) return;

    int mid = (R + L) / 2;
    for (int i = L; i < mid; i++) {
        for (int j = mid; j < R; j++) {
            ans[i][j] = level;
        }
    }

    level++;
    solve(L, mid, level);
    solve(mid, R, level);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int level = 1;
    solve(0, n, level);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << ans[i][j] << " \n"[j + 1 == n];
        }
    }
    return 0;
}