// 4/30
// 過去問攻略

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <deque>
using namespace std;

int main() {
    long long N, P;
    string S;

    cin >> N >> P;
    cin >> S;
    
    long long ans = 0;

    if (P == 2) {
        for (int i = 0; i < N; i++) {
            int s = S[i] - '0';
            if (s % 2 == 0) {
                // cout << s << endl;
                // ans += ((i + 1) * (i + 2)) / 2;
                ans += i + 1;
            }
        }

        cout << ans << endl;
        return 0;
    }

    if (P == 5) {
        for (int i = 0; i < N; i++) {
            int s = S[i] - '0';
            if (s % 5 == 0) {
                // cout << s << endl;
                ans += i + 1;  // ((i + 1) * (i + 2)) / 2;
            }
        }

        cout << ans << endl;
        return 0;
    }

    else {
        long long dp[P] = {0};
        dp[0] = 1;

        long long val = 0;
        long long moddigit = 1;

        for (int i = 0; i < N; i++) {
            val = (val + (S[N - 1 - i] - '0') * moddigit) % P;
            dp[val]++;
            moddigit = (moddigit * 10) % P;
        }
        
        for (int i = 0; i < P; i++) {
            ans += dp[i] * (dp[i] - 1) / 2;
        }

        cout << ans << endl;
        return 0;
    }
}
