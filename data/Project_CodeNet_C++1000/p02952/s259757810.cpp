#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int len(int n) {
    return log10(n) + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    Rep (i, 1, n + 1) {
        if (len(i) % 2) res++;
    }
    cout << res << endl;
}