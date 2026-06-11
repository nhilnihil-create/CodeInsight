#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
using Int = long long;
const auto MOD = 1000000007LL;
int main() {
    Int n;
    cin >> n;
    auto a = vector<Int>(3, 0);
    Int ans = 1;
    rep(i, n) {
        Int x;
        cin >> x;
        if (x == 0) {
            if (a[0] == 0) {
                a[0] = 1;
                ans *= 3;
                ans %= MOD;
            } else if (a[1] == 0) {
                a[1] = 1;
                ans *= 2;
                ans %= MOD;
            } else if (a[2] == 0) {
                a[2] = 1;
            } else {
            	puts("0");
            	return 0;
            }
        } else {
            if (x == a[0] && x == a[1] && x == a[2]) {
                ans *= 3;
                ans %= MOD;
                a[0]++;
            } else if (x == a[0] && x == a[1]) {
                ans *= 2;
                ans %= MOD;
                a[0]++;
            } else if (x == a[1] && x == a[2]) {
                ans *= 2;
                ans %= MOD;
                a[1]++;
            } else if (x == a[2] && x == a[0]) {
                ans *= 2;
                ans %= MOD;
                a[2]++;
            } else if (x == a[0]) {
                a[0]++;
            } else if (x == a[1]) {
                a[1]++;
            } else if (x == a[2]) {
                a[2]++;
            } else {
            	puts("0");
            	return 0;
            }
        }
    }

    cout << (ans%MOD) << endl;
}
