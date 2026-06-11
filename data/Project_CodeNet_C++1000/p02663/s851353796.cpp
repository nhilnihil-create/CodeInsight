#include <bits/stdc++.h>
using namespace std;

int main() {
    int h[2], m[2];
    int k;

    cin >> h[0] >> m[0] >> h[1] >> m[1] >> k;

    int tot = (h[1] - h[0]) * 60;

    if (m[0] <= m[1]) {
        tot += m[1] - m[0];
    } else {
        tot -= 60;
        tot += (60 - m[0]) + m[1];
    }

    cout << tot - k;

    return 0;
}
