#include <bits/stdc++.h>
#define ll long long
inline int roundup(int a, int b) { return (((a + (b -1)) / b)); }
using namespace std;

signed main(void) {
    ll x, y;
    ll n, d, count = 0;
    cin >> n >> d;
    ll d_sq = d*d;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if((x*x + y*y) <= d_sq ) {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}