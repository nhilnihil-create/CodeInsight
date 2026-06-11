#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i);
    }
    sort(l.begin(), l.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l.at(i) + l.at(j) > l.at(k)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
