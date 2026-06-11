#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        ans += i;
    }

    cout << ans << endl;

    return 0;
}
