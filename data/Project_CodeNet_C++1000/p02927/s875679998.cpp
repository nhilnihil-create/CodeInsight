#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int i = 22; i <= D; i++) {
        if (i % 10 >= 2 && i % 10 * (i / 10) <= M)
            ans++;
    }
    cout << ans << endl;

    return 0;
}