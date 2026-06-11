#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int)1e5, MOD = (int)1e9 + 7, INF = (int)3e18;

int pref[N][5];

main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    pref[0][0] = (s[0] == 'R');
    pref[0][1] = (s[0] == 'B');
    pref[0][2] = (s[0] == 'G');
    for (int i = 1; i < n; ++i) {
        pref[i][0] = pref[i - 1][0] + (s[i] == 'R');
        pref[i][1] = pref[i - 1][1] + (s[i] == 'B');
        pref[i][2] = pref[i - 1][2] + (s[i] == 'G');
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int k = -1;
            if (s[i] == 'R' && s[j] == 'B') k = 2;
            if (s[i] == 'B' && s[j] == 'R') k = 2;
            if (s[i] == 'R' && s[j] == 'G') k = 1;
            if (s[i] == 'G' && s[j] == 'R') k = 1;
            if (s[i] == 'G' && s[j] == 'B') k = 0;
            if (s[i] == 'B' && s[j] == 'G') k = 0;
            if (k == -1) 
                continue;
            int l = j + (j - i);
            if (l < n) {
                ans += pref[n - 1][k] - pref[l][k];
                ans += pref[l - 1][k] - pref[j][k];
            }      
            else {
                ans += pref[n - 1][k] - pref[j][k];
            }
        }
    }
    cout << ans;
    return 0;
}