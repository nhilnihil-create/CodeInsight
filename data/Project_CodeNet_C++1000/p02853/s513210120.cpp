#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int f(int x) {
    if (x == 1) {
        return 300000;
    }
    else if (x == 2) {
        return 200000;
    }
    else if (x == 3) {
        return 100000;
    }
    else {
        return 0;
    }
}

int main() {
    int x, y; cin >> x >> y;
    int ans = 0;
    ans += f(x) + f(y);
    if (x == y && x == 1) {
        ans += 400000;
    }
    cout << ans << endl;
    return 0;
}
