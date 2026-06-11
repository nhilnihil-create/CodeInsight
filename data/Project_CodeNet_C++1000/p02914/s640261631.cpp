#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> xs(n);
    for (auto& x : xs) {
        cin >> x;
    }
    long long total_xor = 0;
    for (auto x : xs) {
        total_xor ^= x;
    }
    int K = 62;
    vector<long long> spanning(K, -1);
    for (auto x : xs) {
        x = x & (~total_xor);
        for (int bit = K-1; bit >= 0; --bit) {
            if (!(x & (1LL << bit))) {
                continue;
            }
            if (spanning[bit] == -1) {
                spanning[bit] = x;
                break;
            }
            x ^= spanning[bit];
        }
    }
    long long best = 0;
    for (int bit = K-1; bit >= 0; --bit) {
        if (spanning[bit] == -1) {
            continue;
        }
        if (!(best & (1LL << bit)) && spanning[bit] != -1) {
            best ^= spanning[bit];
        }
    }
    cout << (best + (best^total_xor)) << endl;
    return 0;
}
