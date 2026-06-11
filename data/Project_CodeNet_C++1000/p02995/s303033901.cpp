#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = (c*d)/__gcd(c, d),
        cnt_a = (a-1)/c + (a-1)/d - (a-1)/e,
        cnt_b = b/c + b/d - b/e;
    cout << b-a+1-cnt_b+cnt_a;
}
