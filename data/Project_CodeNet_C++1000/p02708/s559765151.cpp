#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll i = K; i <= N + 1; i++) {
        ll maximum, minimum;
        maximum = minimum = 0;
        maximum = i * (N + (N - (i - 1))) / 2;
        minimum = i * (0 + i - 1) / 2;
        ans = (ans + (maximum - minimum + 1)) % 1000000007;
    }
    cout << ans << endl;
}
