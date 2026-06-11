#include<bits/stdc++.h>

using namespace std;
using lint = long long;

int main() {
    string s;
    lint K;
    cin >> s >> K;

    int n = s.size();
    vector<lint> vt = {1};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) vt.back()++;
        else vt.push_back(1);
    }

    // すべての文字が同じ場合
    if (vt.size() == 1) {
        cout << vt[0] * K / 2 << endl;
        return 0;
    }

    // 違う文字が含まれる場合
    lint ans = 0;
    for (int x : vt) ans += x / 2;
    ans *= K;
    if (s[0] == s[n - 1]) {
        lint a = vt.front(), b = vt.back();
        ans -= (a / 2 + b / 2 - (a + b) / 2) * (K - 1);
    }
    cout << ans << endl;
    return 0;
}
