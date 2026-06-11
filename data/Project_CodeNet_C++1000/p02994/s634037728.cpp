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

    int sum = 0;
    int minAbsT = MOD;
    int minT = MOD;
    rep(i, N) {
        int taste = L + (i + 1) - 1;
        sum += taste;
        if (abs(taste) < minAbsT) {
            minAbsT = abs(taste);
            minT = taste;
        }
    }

    int ans = sum - minT;

    cout << ans << endl;

    return 0;
}
