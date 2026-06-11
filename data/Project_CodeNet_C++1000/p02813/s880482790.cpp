#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }
    vector<vector<int>> b(2, vector<int>(n)), c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    int f = 0;
    int s = 0;
    int cnt = 0;
    do {
        if (a == b[0]) f = cnt;
        if (a == b[1]) s = cnt;
        cnt++;
    } while (next_permutation (a.begin(), a.end()));
    cout << abs (f - s);


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
