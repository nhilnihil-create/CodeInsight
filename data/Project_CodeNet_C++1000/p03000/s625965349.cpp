#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    int l[n];
    rep(i, n) cin >> l[i];

    int res = 1, len = 0;
    rep(i, n) {
        len += l[i];
        if (len <= x) res++;
    }
    cout << res << endl;
}