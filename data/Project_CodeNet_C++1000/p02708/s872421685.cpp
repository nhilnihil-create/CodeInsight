#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    ll output = 0;

    for (ll i = K; i <= N + 1; i++) {
        ll min = (i - 1) * i / 2;
        ll max = (2 * N - i + 1) * i / 2;
        min %= 1000000007;
        max %= 1000000007;
        ll tmp = max - min + 1;
        tmp %= 1000000007;
        output += tmp;
        output %= 1000000007;
    }
    if (output < 0) {
        output += 1000000007;
    }

    cout << output << endl;

    return 0;
}
