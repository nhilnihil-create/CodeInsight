#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll N, K;
    cin >> N >> K;

    int ans = 0;
    while (N > 0) {
        N /= K;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
