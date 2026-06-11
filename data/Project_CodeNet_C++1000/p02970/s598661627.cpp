#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, D;
    cin >> N >> D;

    double range = 2 * D + 1;

    int ans = ceil(N / range);

    cout << ans << endl;

    return 0;
}
