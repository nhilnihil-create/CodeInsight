#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    cout << t2 - t1 - k << endl;

    return 0;
}