#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int s = 7, ans = 1;
    while (ans <= k) {
        if (s % k == 0) {
            cout << ans << endl;
            return 0;
        }
        s = (s % k)*10 + 7;
        ans++;
    }
    cout << -1 << endl;
}