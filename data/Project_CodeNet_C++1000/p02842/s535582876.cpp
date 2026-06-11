#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    int n;
    cin >> n;

    int te_ceil = ceil(n / 1.08);
    int te_floor = floor(n / 1.08);

    int te_ceil_int = te_ceil * 1.08;
    int te_floor_int = te_floor * 1.08;

    if (te_ceil_int == n || te_floor_int == n) {
        if (te_ceil_int == n) {
            cout << te_ceil << endl;
        } else {
            cout << te_floor << endl;
        }
    } else {
        cout << ":(" << endl;
    }
}