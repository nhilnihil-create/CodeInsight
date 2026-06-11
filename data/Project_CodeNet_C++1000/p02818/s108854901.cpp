#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using llint = long long int;
using namespace std;

int main() {
    fastIO;

    unsigned long long int a, b, k;
    cin >> a >> b >> k;
    if (a + b < k)
        cout << 0 << " " << 0 << endl;
    else if (a >= k)
        cout << a - k << " " << b << endl;
    else
        cout << 0 << " " << b - (k - a) << endl;
}
