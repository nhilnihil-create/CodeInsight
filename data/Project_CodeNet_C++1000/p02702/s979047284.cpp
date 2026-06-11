#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    string S;
    cin >> S;
    int n = S.length();
    
    if (n < 4) {
        cout << "0\n";
        return 0;
    }
    
    ll dp[n + 1]{};
    int k = 1;
    ll a[2019]{};
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        int j = n - i - 1;
        int c = S[j] - '0';
        dp[i + 1] = (dp[i] + c * k) % 2019;
        k = (k * 10) % 2019;
        a[dp[i + 1]]++;
    }
    ll ans = 0;
    for (int i = 0; i < 2019; i++) {
        ans += (a[i] * (a[i] - 1)) / 2;
    }
    cout << ans << "\n";
    return 0;
}