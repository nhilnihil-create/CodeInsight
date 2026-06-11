#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, t; cin >> n >> x >> t;
    cout << (n + x - 1) / x * t << endl;
    return 0;
}

