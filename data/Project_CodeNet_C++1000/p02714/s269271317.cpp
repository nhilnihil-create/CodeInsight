#include <bits/stdc++.h>
using namespace std;

// D - RGB Triplets
int main() {
    int N;
    string S;
    cin >> N >> S;

    if (N < 3) {
        cout << 0;
        return 0;
    }

    int r = 0, g = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') r++;
        if (S[i] == 'G') g++;
        if (S[i] == 'B') b++;
    }

    // long long all = (long long)r * g * b;

    int minus = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (j + (j - i) >= N) break;
            if (S[i] != S[j] && S[i] != S[j + (j - i)] && S[j + (j - i)] != S[j]) {
                // cout << "i:" << i << S[i] << ", j:" << j << S[j] << ", k:" << j + (j - i) << S[j + (j - i)] << endl;
                minus++;
                // all--;
            }
        }
    }

    long long all = (long long)r * g * b;
    cout << all - minus;
    // cout << (long long)(r * g * b) - minus;
}
