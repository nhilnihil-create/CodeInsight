#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    if(A > K) {
        A = A - K;
    } else {
        K = K - A;
        A = 0;
        if (B > K) {
            B = B - K;
        } else {
            B = 0;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}
