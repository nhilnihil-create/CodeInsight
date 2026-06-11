#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int k;
    int ans = 0;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1; l <= k; ++l) {
                ans += __gcd(__gcd(i, j), l);
            }
        }
    }
    cout << ans << endl;
    return 0;
}