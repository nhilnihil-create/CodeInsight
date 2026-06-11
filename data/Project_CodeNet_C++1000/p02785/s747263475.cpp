#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> H(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> H[i];
    }

    sort(H.begin(), H.end(), greater<long long>());
    for (long long i = 0; i < N; ++i) {
        if (K > 0) {
            H[i] = 0;
        }
        else {
            break;
        }
        --K;
    }

    long long ans = accumulate(H.begin(), H.end(), 0LL);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
