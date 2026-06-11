#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m = 0; cin >> n;
    long long s = 0;
    while (n--) {
        int a; cin >> a;
        s += max(0, m - a);
        m = max(m, a);
    }
    cout << s << endl;
    return 0;
}

