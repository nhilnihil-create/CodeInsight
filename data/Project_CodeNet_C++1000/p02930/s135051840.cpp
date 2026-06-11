#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N], n;

void solve(int L, int R, int k) {
	if (L == R) return;
    int m = L + R >> 1;
    for (int i = L; i <= m; i ++) for (int j = m+1; j <= R; j ++) a[j][i] = a[i][j] = k;
    solve(L, m, k+1);
    solve(m+1, R, k+1);
    return;
}

int main() {
    scanf("%d", &n);
    solve(1, n, 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = i+1; j <= n; j ++) printf("%d%c", a[i][j], " \n"[j==n]);
    }
	return 0;
}
