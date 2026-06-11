#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int a[2005];

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int d = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            d = min(j - i, abs(x - i) + 1 + abs(y - j));
            a[d]++;
        }
    }

    for (int i = 1; i < n; i++) cout << a[i] << endl;
    return 0;
}
