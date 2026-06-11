#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    rep (i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n, greater<int>());
    rep (i, n) {
        if (a[0] == b[i]) cout << a[1] << endl;
        else cout << a[0] << endl;
    }
}