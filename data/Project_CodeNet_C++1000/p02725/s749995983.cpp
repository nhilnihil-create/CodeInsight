#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    int maxLength = k - a.at(n - 1) + a.at(0);
    for (int i = 1; i < n; i++) {
        maxLength = max(maxLength, a.at(i) - a.at(i - 1));
    }

    int ans = k - maxLength;

    cout << ans << endl;

    return 0;
}
