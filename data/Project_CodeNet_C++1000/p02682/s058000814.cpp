#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k <= a) cout << k << endl;
    else {
        int tmp = k - a;
        if (tmp <= b) cout << a << endl;
        else cout << a - (tmp - b) << endl;
    }
}