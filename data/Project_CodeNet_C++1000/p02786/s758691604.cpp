#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h;
    cin >> h;

    if (h == 1) {
        cout << 1 << endl;
        return 0;
    }
    long long index = 1;
    long long cnt = 1;
    while (1) {
        if (cnt >= h) break;
        index *= 2;
        cnt += index;
    }

    cout << cnt << endl;

    return 0;
}
