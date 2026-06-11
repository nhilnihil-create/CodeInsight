#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d, a;
    cin >> n >> k;

    vector<bool> snk(n,true);
    for (int i = 0; i < k; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> a;
            snk[a-1] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (snk[i]) ans++;
    }

    cout << ans << endl;
}