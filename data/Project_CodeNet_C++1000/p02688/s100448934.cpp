#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> snuke(n, true);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            snuke.at(a - 1) = false;
        }
    }
    int ans = 0;
    for (bool x : snuke) {
        if (x == true) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
