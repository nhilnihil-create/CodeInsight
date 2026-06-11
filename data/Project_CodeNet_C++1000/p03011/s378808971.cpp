#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int p, q, r;
    cin >> p >> q >> r;

    int min = p + q;
    if (min > p + r) min = p + r;
    if (min > q + r) min = q + r;
    cout << min << endl;
}