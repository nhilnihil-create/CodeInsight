/**
    BISMILLAH
    @Author : Arham
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y, a, b, c, d;
    cin >> a >> b >> c >> d;
    long long one, two, three, four;
    one = a * c;
    two = a * d;
    three = b * c;
    four = b * d;
    long long fin = max(max(one, two), max(three, four));
    cout << fin << endl;

    return;
}

int main() {
    int t = true;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}
