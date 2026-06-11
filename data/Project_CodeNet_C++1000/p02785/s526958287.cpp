#include <bits/stdc++.h>
using namespace std;

// C - Fennec vs Monster
int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> H(N);
    for (long long i = 0; i < N; i++) {
        cin >> H[i];
    }
    sort(H.begin(), H.end(), greater<long long>());
    if (N - K <= 0) {
        cout << 0;
        return 0;
    }
    long long countAtack = 0;
    for (long long i = K; i < N; i++) {
        // cout << H[i] << endl;   // debug
        countAtack += H[i];
    }
    cout << countAtack;
}
