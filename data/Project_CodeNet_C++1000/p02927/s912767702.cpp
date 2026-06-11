#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int i = 21; i <= D; ++i) {
        if (i % 10 < 2) continue;
        if ((i % 10) * (i / 10) <= M) ans++;
    }

    cout << ans << '\n';
    return 0;
}
