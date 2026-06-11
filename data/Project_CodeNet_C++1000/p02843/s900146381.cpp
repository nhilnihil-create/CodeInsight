#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x % 100 <= x / 100 * 5)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
