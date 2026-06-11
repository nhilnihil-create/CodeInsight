#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll a, b, c;
    if (K - A > 0) {
        a = A;
        if((K - A) - B > 0) {
            b = B;
            if((K - A - B) - C > 0) {
                c = C;
            } else {
                c = K - A - B;
            }
        } else {
            b = K - A;
            c = 0;
        }
    } else {
        a = K;
        b = 0;
        c = 0;
    }

    ll ans = a * 1 + b * 0 + c * (-1);

    cout << ans << endl;

    return 0;
}
