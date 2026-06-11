#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int curr, tmp = -1, cnt = 0, max_c = 0;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (curr <= tmp) {
            cnt++;
        } else {
            if (max_c < cnt) max_c = cnt;
            cnt = 0;
        }
        tmp = curr;
    }

    cout << max(max_c, cnt) << endl;

    return 0;
}
