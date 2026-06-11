#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    long cnt = 0;
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (s[i] == s[j]) cnt++;
    //     }
    // }
    long ans = 0;
    if (n == 2) {
        if (s[0] == s[1]) {
            ans = 1;
        }
    } else {
        rep(i, n-1) {
            if (s[i] == s[i+1]) {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            if (i == n-2) {
                ans += cnt * (cnt + 1) / 2;
            }
        }
    }
    cout << ans << endl;
    // string s = "acornistnt";
    // sort(s.begin(), s.end());
    // cout << s << endl;
}