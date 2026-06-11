#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;

int main() {
    fastIO;
    lint a, b;
    cin >> a >> b;
    if ((a - b) % 2 == 0)
        cout << abs(a + b) / 2;
    else
        cout << "IMPOSSIBLE";
}