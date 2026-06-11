#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int k;
    cin >> k;

    k -= 400;
    k /= 200;

    cout << 8 - k << endl;

    return 0;
}