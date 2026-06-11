#include <iostream>
#include <bits/stdc++.h>

#define MAXN 1000010
#define endl '\n'


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    int M = m;
    int b[m];
    while (M--) cin >> b[m - M - 1];
    int sum[n];
    for (int l = 0; l < n; ++l) {
        sum[l] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i] += matrix[i][j] * b[j];
        }
    }
    for (int k = 0; k < n; ++k) {
        cout << sum[k] << endl;
    }
    return 0;
}
