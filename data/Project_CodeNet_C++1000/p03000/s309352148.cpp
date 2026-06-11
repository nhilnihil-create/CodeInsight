#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;

    int ans = 1;
    int l = 0;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        int tmp = d + l;
        if (tmp <= x) {
            ans++;
            d = tmp;
        } else {
            break;
        }
    }
    cout << ans << endl;
}

