#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    int ans = 1000;
    if(p + q < ans) ans = p + q;
    if(r + q < ans) ans = r + q;
    if(p + r < ans) ans = p + r;
    if(q + r < ans) ans = q + r;
    if(r + p < ans) ans = r + p;
    if(q + p < ans) ans = q + p;

    cout << ans << endl;
    return 0;
}
