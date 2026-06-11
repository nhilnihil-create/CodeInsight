#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int amt = min(a, k);
    a -= amt;
    k -= amt;
    int sum = amt;
    amt = min(b, k);
    k -= amt;
    amt = min(c, k);
    sum -= amt;
    cout << sum << '\n';
}
/*

 */