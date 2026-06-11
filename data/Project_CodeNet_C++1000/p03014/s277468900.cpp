#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 5;
const int M = 2000 + 5;

char g[N][M];

struct Data {
    int l, r, u, d;

    Data () {}
} stat[N][M];

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            stat[i][j].l = (g[i][j] == '#' ? 0 : stat[i][j - 1].l + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            stat[i][j].r = (g[i][j] == '#' ? 0 : stat[i][j + 1].r + 1);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            stat[i][j].u = (g[i][j] == '#' ? 0 : stat[i - 1][j].u + 1);
        }
    }
    for (int j = m; j >= 1; j--) {
        for (int i = n; i >= 1; i--) {
            stat[i][j].d = (g[i][j] == '#' ? 0 : stat[i + 1][j].d + 1);
        }
    }
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int lit = stat[i][j].l + stat[i][j].r + stat[i][j].u + stat[i][j].d - 4 + 1;
            mx = max(mx, lit);
        }
    }
    cout << mx << '\n';
}