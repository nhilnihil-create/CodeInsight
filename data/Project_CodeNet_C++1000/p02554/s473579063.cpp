#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    long long all = 1, ex_0 = 1, ex_9 = 1, ex_09 = 1;
    for (int i = 0; i < n; i++) {
        all = (all * 10) % MOD;
        ex_0 = (ex_0 * 9) % MOD;
        ex_9 = (ex_9 * 9) % MOD;
        ex_09 = (ex_09 * 8) % MOD;
    }
    long long ans = (all - ex_0 - ex_9 + ex_09) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
