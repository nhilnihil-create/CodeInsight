#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, m, a;
    cin >> n >> m;
    rep(i, m) {
        cin >> a;
        n -= a;
    }
    if (n < 0)
        cout << -1 << endl;
    else
        cout << n << endl;
    return 0;
}