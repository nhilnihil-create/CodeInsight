#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 202020;

int dp1[MAX_N], dp2[MAX_N];

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i > 0) dp1[i] = max(dp1[i], dp1[i - 1]);
        if (s[i] == 'x') continue;
        if (i - c - 1 >= 0) dp1[i] = max(dp1[i], dp1[i - c - 1] + 1);
        dp1[i] = max(dp1[i], 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) dp2[i] = max(dp2[i], dp2[i + 1]);
        if (s[i] == 'x') continue;
        if (i + c + 1 < n) dp2[i] = max(dp2[i], dp2[i + c + 1] + 1);
        dp2[i] = max(dp2[i], 1);
    }
    for (int i = 0; i < n; i++) {
        int le = 0, ri = 0;
        if (i == 0) {
            ri = dp2[i + 1];
        } else if (i == n - 1) {
            le = dp1[i - 1];
        } else {
            le = dp1[i - 1], ri = dp2[i + 1];
        }
        if (le + ri < k) {
            cout << i + 1 << endl;
        }
    }
}