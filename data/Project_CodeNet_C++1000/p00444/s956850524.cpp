#include <bits/stdc++.h>
using namespace std;

int change[6] = {500, 100, 50, 10, 5, 1};

int main(void) {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        n = 1000 - n;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            int t = floor(n/change[i]);
            n -= change[i]*t;
            cnt += t;
        }
        cout << cnt << endl;
    }
    return 0;
}
