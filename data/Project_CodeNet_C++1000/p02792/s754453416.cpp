#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int freq[10][10], n, x, y;
long long res;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        x = i, y = x % 10;
        while (x >= 10)
            x /= 10;
        ++freq[x][y];
    }
    for (int i = 1; i < 10; ++i)
        for (int j = 1; j < 10; ++j)
            res += freq[i][j] * freq[j][i];
    cout << res;
    PLEC
}
