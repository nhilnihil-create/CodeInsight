#include<bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c, k, ans = 0;
    cin >> a >> b >> c >> k;

    if (k <= a) {
        ans = k;
    }
    else {
        ans = a;
        k -= a;
        if (b < k) {
            ans -= k-b;
        }
    }
    cout << ans << endl;
}