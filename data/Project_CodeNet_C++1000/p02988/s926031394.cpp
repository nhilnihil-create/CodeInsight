#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

bool check(int a, int b, int c) {
    if (a < c) {
        if (a < b && b < c) return true;
    } else {
        if (c < b && b < a) return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int p[n];
    rep (i, n) {
        cin >> p[i];
    }
    int res = 0;
    Rep (i, 1, n - 1) {
        if (check(p[i-1], p[i], p[i+1])) res++;
    }
    cout << res << endl;
}