#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    N %= K;
    if (abs(N - K) < N) {
        N = abs(N - K);
    }

    cout << N << endl;

    return 0;
}
