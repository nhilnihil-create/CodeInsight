#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    int num = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == num) {
            num++;
        } else {
            cnt++;
        }
    }

    if (n == cnt) {
        cout << -1 << endl;
    } else {
        cout << cnt << endl;
    }

    return 0;
}
