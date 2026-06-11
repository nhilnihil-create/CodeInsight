#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int h1, m1; cin >> h1 >> m1;
    int h2, m2; cin >> h2 >> m2;
    int k; cin >> k;

    int m = 0;
    if (h2 >= h1) {
        m += (h2 - h1) * 60;
    } else {
        m += ((h2 + 24) - h1) * 60;
    }

    if (m2 >= m1) {
        m += m2 - m1;
    } else {
        m -= 60;
        m += (m2 + 60) - m1;
    }

    cout << m - k << endl;
}