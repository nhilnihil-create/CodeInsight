#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while(a >= b && k--) b *= 2;
    while(k--) c *= 2;
    cout << (a < b && b < c ? "Yes" : "No") << '\n';
    return 0;
}
