#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


signed main() {
    int N, K;
    cin >> N >> K;

    ll cnt = 0;
    ll k = K;
    int n = N;
    while (1) {
        n = n / k;
        if (n != 0) {
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt + 1 << endl;

}
