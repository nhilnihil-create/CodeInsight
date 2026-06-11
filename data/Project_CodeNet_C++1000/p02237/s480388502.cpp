#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main()
{
    int n;
    cin >> n;
    int A[n][n] = {};
    rep(i, 0, n) {
        int u, k;
        cin >> u >> k;
        rep(j, 0, k) {
            int v;
            cin >> v;
            A[u - 1][v - 1] = 1;
        }
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (j == n - 1) cout << A[i][j] << endl;
            else cout << A[i][j] << " ";
        }
    }
    return 0;
}

