#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long a, b;
    cin >> a >> b;
    cout << a * b / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
