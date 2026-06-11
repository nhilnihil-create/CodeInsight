#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '1';

    int ans = 0;
    if (s.find("2") != string::npos) {  
        for (int i = 0; i < n; i++) {
            int val = (a[i] & 1);
            if (((n - 1) & i) == i) ans ^= val;
        }
    } else {
        for (int i = 0; i < n; i++) {
            int val = min(a[i], 1);
           if (((n - 1) & i) == i) ans ^= val;
        }
        ans *= 2;
    }

    cout << ans << '\n';

    return 0;
}