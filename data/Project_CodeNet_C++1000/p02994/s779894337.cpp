#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, L;
    cin >> N >> L;

    int sum1 = 0;
    rep(i, N) {
        int taste = L + (i + 1) - 1;
        sum1 += taste;
    }

    int minDiff = MOD;
    int ans = 0;
    rep(i, N) {
        int taste = L + (i + 1) - 1;
        int sum2 = sum1 - taste;
        if (abs(sum1 - sum2) < minDiff) {
            minDiff = abs(sum1 - sum2);
            ans = sum2;
        }
    }

    cout << ans << endl;

    return 0;
}
