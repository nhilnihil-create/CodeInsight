#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 +7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(10, vector<int>(10));
    for (int i = 1; i <= n; i++) {
        int r = i % 10;
        int x = i;
        int l;
        while (x) {
            l = x % 10;
            x /= 10;
        }
        c[l][r]++;
    }
    long long ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            ans += c[i][j] * c[j][i];
        }
    }
    cout << ans;

    return 0;
}