#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N, K, S;
    cin >> N >> K >> S;
    int64_t S_zurasi = S + 1;
    if (S == 1000000000) {
        S_zurasi = S - 1;
    }
    for (int i=0; i < N; i++) {
        if (i < K) {
            cout << S;
        } else {
            cout << S_zurasi;
        }

        if (i < N-1) {
            cout << " ";
        }
    }

    cout << endl;
    return 0;
}