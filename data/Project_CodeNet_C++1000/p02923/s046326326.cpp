#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
int n, a[NMAX], dp[NMAX], sol;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[n] = 1;
    sol = 1;
    for(int i = n - 1; i >= 1; i --) {
        if(a[i] >= a[i + 1]) {
            dp[i] = 1 + dp[i + 1];
        } else {
            dp[i] = 1;
        }
        sol = max(sol, dp[i]);
    }
    cout << sol - 1;
    return 0;
}