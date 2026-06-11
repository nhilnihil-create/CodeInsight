#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll A[100005];
ll B[65];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    cout << ((~0) & 1) << endl;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        sum ^= A[i];
    }
    for (int i = 1; i <= n; ++i) {
        A[i] = A[i] & ~sum;
        for (int j = 60; j--;) {
            if ((A[i] >> j) & 1) {
                if (B[j] == 0) {
                    B[j] = A[i];
                    break;
                } else {
                    A[i] ^= B[j];
                }
            }
        }
    }
    ll x = 0;
    for (int i = 60; i--;)
        x = max(x, x ^ B[i]);
    cout << (x + (x ^ sum));
    return 0;
}
