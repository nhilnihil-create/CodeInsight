#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int res = (c-a+b > 0) ? c-a+b : 0;
    cout << res << endl;
}