#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, t;
    cin >> n >> m;

    int b[m], A[n][m];
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            cin >> t;
            A[j][i] = t;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> t;
        b[i] = t;
    }

    for (int j = 0; j < n; ++j) {
        int x = 0;

        for (int i = 0; i < m; ++i) {
            x += b[i] * A[j][i];
        }

        cout << x << endl;
    }

    return 0;
}