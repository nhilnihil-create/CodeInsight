#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a == 0) {
            ans = 0;
            cout << ans << endl;
            return 0;
        }
        else if (a <= 1000000000000000000 / ans) {
            ans = ans * a;
        }
        else {
            ans = -1;
        }
    }
    cout << ans << endl;
    return 0;
}