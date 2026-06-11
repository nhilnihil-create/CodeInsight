#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0, tmp;
    while (cnt++ < 50000) {
        tmp = cnt * 1.08;
        if (tmp == n) break;
    }

    if(cnt < 50000) {
        cout << cnt << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
