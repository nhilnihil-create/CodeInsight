#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;
    a += b;
    if (a == 3)
        cout << 3;
    else if (a == 4)
        cout << 2;
    else
        cout << 1;
}
