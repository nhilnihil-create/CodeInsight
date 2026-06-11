#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> b.at(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> c.at(i);
    }

    int ans = 0, temp = 0, cnt = 0;
    for (int i:a) {
        if (temp == 0) {
            temp = i;
            ans += b[i - 1];
        } else {
            ans += b[i - 1];
            if (a[cnt - 1] + 1 == a[cnt]) {
                ans += c[i - 1 - 1];
            }
        }
        cnt++;
    }

    cout << ans << endl;

}