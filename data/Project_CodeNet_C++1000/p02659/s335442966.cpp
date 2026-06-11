#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回

int main() {
    ll a;
    double b;
    cin >> a >> b;

    ll tmp = b * 100 + 0.5;

    ll ans = (a * tmp) / 100;

    cout << ans << endl;

    return 0;
}

// 100000000000001 0.01