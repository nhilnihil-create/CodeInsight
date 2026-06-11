#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    for (int i = 0; i < k; i++) {
        if (b <= a) b *= 2;
        else if (c <= b) c *= 2;
    }

    if (b > a && c > b) cout << "Yes" << endl;
    else cout << "No" << endl;
}