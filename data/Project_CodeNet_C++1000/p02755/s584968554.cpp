#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;

    int ans = INF;
    for (int i = 1; i <= 1250; i++) {
        if (int(i*0.08) == a && int(i*0.1) == b) {
            ans = min(ans, i);
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
