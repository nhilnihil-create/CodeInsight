#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if ((b - a) % 2 == 0)
        cout << (b - a) / 2;
    else
        cout << min(a - 1, n - b) + (b - a - 1) / 2 + 1;
    cout << endl;

    return 0;
}