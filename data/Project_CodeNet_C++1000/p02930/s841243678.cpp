#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

int ans[501][501];

void fill(int start, int end, int color) {
    if (end - start < 3) {
        if (end - start == 1) ans[start][end] = color;
        else {
            ans[start][start+1] = color;
            ans[start][end] = color+1;
            ans[start+1][end] = color+1;
        }
        return;
    }
    int m = (start+end)/2;
    for (int i = start; i <= m; i++) {
        for (int j = m+1; j <= end; j++) {
            ans[i][j] = color;
        }
    }
    fill(start, m, color+1);
    fill(m+1, end, color+1);
}

void solve() {
    int n; sc(n);
    fill(1, n, 1);
    for(int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}