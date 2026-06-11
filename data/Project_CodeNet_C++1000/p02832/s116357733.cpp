#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, x;
bool dp[200002];
int main() {
    DAU
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        dp[x] |= dp[x-1];
    }
    for (int i = n; i; --i)
        if (dp[i]) {
            cout << n - i;
            PLEC
        }
    cout << -1;
    PLEC
}