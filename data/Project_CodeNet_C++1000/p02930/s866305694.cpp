#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            bitset<64> bit_i = bitset<64>(i);
            bitset<64> bit_j = bitset<64>(j);
            for (ll k = 0; ; k++) {
                if (bit_i[k] != bit_j[k]) {
                    cout << k + 1 << " \n"[j == N - 1];
                    break;
                }
            }
        }
    }
}