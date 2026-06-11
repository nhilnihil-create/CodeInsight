#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int32_t main() {
    start();
    int ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])ans++;
    }
    cout << ans;
    return 0;
}