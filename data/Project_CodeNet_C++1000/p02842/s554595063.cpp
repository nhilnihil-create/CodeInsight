#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp = n * 100 / 108;

    int ans = 0;
    if ((int)(tmp * 1.08) == n) {
        ans = tmp;
    }
    if ((int)((tmp+1) * 1.08) == n) {
        ans = tmp + 1;
    }

    if (ans != 0) {
        cout << ans << endl;
    }
    else {
        cout << ":(" << endl;
    }
}
