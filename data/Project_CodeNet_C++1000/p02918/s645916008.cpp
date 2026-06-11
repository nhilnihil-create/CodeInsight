#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> b;
    for (auto x: s) {
        if (x == 'R') b.push_back(false);
        else b.push_back(true);
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (b[i] != b[i+1]) {
            cnt++;
            int d = 1;
            while (i+d < n && b[i+d] != b[i]) {
                b[i+d] = b[i];
                d++;
            }
            i = i + d - 1;
            if (cnt == k) break;
        }
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (b[i] == b[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}