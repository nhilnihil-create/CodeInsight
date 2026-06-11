#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int res = -1, tmp8, tmp10;
    for (int i = 1; i <= 1250; i++) {
        tmp8 = i * 0.08;
        tmp10 = i * 0.1;
        if (tmp8 == a && tmp10 == b) {
            res = i;
            break;
        }
    }

    cout << res << endl;

    return 0;
}
