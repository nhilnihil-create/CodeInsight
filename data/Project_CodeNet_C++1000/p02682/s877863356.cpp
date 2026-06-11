#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c, k; cin >> a >> b >> c >> k;
    int ans;
    if (k <= a) ans = k;
    else if (k <= a + b) ans = a;
    else ans = a - (k - a - b);
    cout << ans << endl;
    return 0;
}