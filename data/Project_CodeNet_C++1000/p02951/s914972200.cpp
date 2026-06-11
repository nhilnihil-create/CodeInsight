#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = c-(a-b);
    if (ans > 0) cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}