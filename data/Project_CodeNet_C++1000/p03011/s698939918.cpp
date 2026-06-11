/**
*    created: 12.05.2020 09:33:35
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    cout << min(min(a + b, b + c), (c + a)) << endl;
    return 0;
}