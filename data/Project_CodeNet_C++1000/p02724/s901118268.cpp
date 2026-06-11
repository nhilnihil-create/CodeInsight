#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll X;
    cin >> X;

    ll ans = 0;
    ans += (X / 500) * 1000;
    ll left = X % 500;
    ans += (left / 5) * 5;

    cout << ans << endl;
    
    return 0;
}
