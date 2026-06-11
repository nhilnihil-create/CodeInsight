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

    ll divided = N;
    string digits = "";
    while (divided > 0) {
        ll left = divided % K;
        digits.push_back('0' + left);
        divided = divided / K;
    }
    reverse(digits.begin(), digits.end());

    int ans = digits.size();

    cout << ans << endl;

    return 0;
}
