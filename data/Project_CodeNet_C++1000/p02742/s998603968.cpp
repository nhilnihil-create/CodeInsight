#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    long long min, max;
    max = (h % 2 == 1) ? h / 2 + 1 : h / 2;
    min = h / 2;

    long long cnt = 0;
    if (h == 1 || w == 1) {
        cnt = 1;
    } else if (w % 2 == 0) {
        cnt = (max + min) * (w / 2);
    } else {
        cnt = (max + min) * (w / 2) + max;
    }

    cout << cnt << endl;

    return 0;
}
