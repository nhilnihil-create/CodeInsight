#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int x, a;
    cin >> x >> a;
    if (x < a) cout << 0 << endl;
    else cout << 10 << endl;
}