#include <bits/stdc++.h>
using namespace std;


int main() {
    int N; cin >> N;
    // A = [7, 1, 15] (= [111, 1, 1111])
    vector<long long int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    long long int ans = 0;

    for (int i = 0; i < 60; i++) {
        int s = 0;
        // for i = 0, s = 1 xor 1 xor 1 = 1
        for (int j = 0; j < N; j++) s ^= A[j] >> i & 1;
        if (s == 1) {
            ans += 1LL << i;
            // for i = 0, A -> [110, 0, 1110]
            for (int j = 0; j < N; j++) A[j] &= ~(1LL << i);
        }
    }

    vector<long long int> bases;
    // A -> [0110, 110, 0]
    sort(A.begin(), A.end(), greater<>());
    for (long long int x : A) {
        // min(110, 110 ^ 0110) = min(110, 0) = 0
        for (long long int y : bases) x = min(x, x ^ y);
        if (x != 0) bases.push_back(x);
    }
    long long s = 0;
    // max(0110, 0110 ^ 0) = 0110
    for (long long int x : bases) s = max(s, s ^ x);

    cout << ans + s * 2 << endl;

    return 0;
}
