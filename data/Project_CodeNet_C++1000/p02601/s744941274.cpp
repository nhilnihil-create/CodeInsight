#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (a >= b) {
        b *= 2;
        k--;
    }
    while (b >= c) {
        c *= 2;
        k--;
    }
    if (k < 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}