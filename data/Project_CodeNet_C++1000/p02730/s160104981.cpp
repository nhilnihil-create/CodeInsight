#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int kaibun(string s, int n, int m) {
    int ans = 1;
    // for (int i = n; i <= m; i++) {
    //     cout << s[i];
    // }
    // cout << endl;
    for (int i = 0; i * 2 < m - n; i++) {
        // cout << "s[" << n + i << "]=" << s[n + i] << " s[" << m - i
        //      << "]=" << s[m - i] << endl;
        if (s[n + i] != s[m - i]) {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    if (kaibun(s, 0, n - 1) && kaibun(s, 0, (n - 2) / 2) &&
        kaibun(s, (n + 3) / 2 - 1, n - 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}