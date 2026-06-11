#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> s(n, 0);
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (i == 0) {
            s[i] = tmp;
        } else {
            s[i] = s[i-1] + tmp;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int s1 = s[i];
        int s2 = s[n-1] - s1;
        if (i == 0) {
            ans = abs(s1 - s2);
        } else {
            if (abs(s1 - s2) < ans) {
                ans = abs(s1 - s2);
            }
        }
    }
    cout << ans << endl;
}

