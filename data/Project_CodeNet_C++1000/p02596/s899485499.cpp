#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k; cin >> k;
    for (int i = 1, x = 7; i <= k; i++) {
        if (x % k == 0) {
            return cout << i << endl, 0;
        }
        x *= 10; x += 7; x %= k;
    }
    cout << -1 << endl;
    return 0;
}
