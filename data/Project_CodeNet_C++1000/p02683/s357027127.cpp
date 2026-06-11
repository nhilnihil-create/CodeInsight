#include <iostream>
using namespace std;

int c[16], a[16][16], n, m, x;
bool v[16];
int ans = 2e9;

void checkSol() {
    for(int j = 1; j <= m; j++) {
        int total = 0;
        for(int i = 1; i <= n; i++)
            if(v[i]) total += a[i][j];
        if(total < x) return;
    }

    int cost = 0;
    for(int i = 1; i <= n; i++)
        if(v[i])
            cost += c[i];

    ans = min(ans, cost);
}

void backtracking(int k) {
    for(int i = 0; i <= 1; i++) {
        v[k] = i;
        if(k == n) {
            checkSol();
        } else {
            backtracking(k+1);
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    for(int j = 1; j <= m; j++) {
        int total = 0;
        for(int i = 1; i <= n; i++)
            total += a[i][j];
        if(total < x) {
            cout << -1;
            return 0;
        }
    }

    backtracking(1);
    cout << ans;
}
