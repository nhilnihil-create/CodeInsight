#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int d[n];
    rep (i, n) cin >> d[i];

    sort(d, d + n);
    int half = n/2 - 1;
    int res = d[half + 1] - d[half];
    cout << res << endl;
}