#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;

long long fpow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = (fpow(10, n) - 2LL * fpow(9, n) + fpow(8, n)) % M;
    if (ans < 0) ans += M;
    cout << ans << '\n';
    return 0;
}
