#include <bits/stdc++.h>

using namespace std;

int G[555][555];

int f(int n, int s, int level) {
    for (int i = 0; i < n/2; ++i) {
        for (int j = n/2; j < n; ++j) {
            G[s+i][s+j] = level;
        }
    }
    if (n <= 2) return 1;
    return max(f(n/2, s, level+1), f(n-n/2, s+n/2, level+1)) + 1;
}

int main() {
    int n;
    cin >> n;
    int res = f(n, 0, 1);
    // cout << res << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) cout << G[i][j] << " \n"[j==n-1];
    }
    return 0;
}
