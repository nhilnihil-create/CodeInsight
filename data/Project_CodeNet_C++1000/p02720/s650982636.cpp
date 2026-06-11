// 6/17 振り返り
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll K;
    cin >> K;

    ll count = 0;
    // ll dp[11];

    // dp[0] = 0;  // 0桁
    // dp[1] = 9;  // 1桁
    // for (int i = 2; i <= 10; i++) {
    //     dp[i] = dp[i-1] * 3 - 1;
    //     printf("dp[%d] = %d\n", i, dp[i]);
    // }

    if (K < 10) {
        cout << K << endl;
        return 0;
    }

    vector<ll> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    count = 9;

    for (int digit = 1; digit <= 11; digit++) {
        vector<ll> b;

        for (auto x : a) {
            ll last = x % 10;

            if (last != 0) {
                b.push_back(x * 10 + last - 1);
                count++;
                if (count == K) {
                    cout << b.back() << endl;
                    return 0;
                }
            }
            
            b.push_back(x * 10 + last);
            count++;
            if (count == K) {
                cout << b.back() << endl;
                return 0;
            }            

            if (last != 9) {
                b.push_back(x * 10 + last + 1);
                count++;
                if (count == K) {
                    cout << b.back() << endl;
                    return 0;
                }
            }
        }

        swap(a, b);
    }
}
