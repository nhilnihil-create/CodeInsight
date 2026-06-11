#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h.at(i);
    }
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (h.at(i) >= h.at(i + 1)) {
            count++;
        } else {
            ans = max(ans, count);
            count = 0;
        }
    }
    ans = max(ans, count);
    cout << ans << endl;
    return 0;
}
