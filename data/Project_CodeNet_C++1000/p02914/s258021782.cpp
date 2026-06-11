#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    int N; cin >> N;
    vector<Int> A(N); for (auto &a : A) cin >> a;
    Int odd = 0;
    for (auto &a : A) odd ^= a;
    for (auto &a : A) a &= ~odd;
    int rank = 0;
    for (int i = 60; i >= 0; i--) {
        int pivot = -1;
        for (int j = rank; j < N; j++) {
            if (A[j] & (1LL << i)) {
                pivot = j;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[rank], A[pivot]);
        for (int j = rank + 1; j < N; j++) {
            if (A[j] & (1LL << i)) {
                A[j] ^= A[rank];
            }
        }
        rank++;
    }
    Int even = 0;
    for (int i = 0; i < rank; i++) {
        even = max(even, even ^ A[i]);
    }
    cout << even + (even | odd) << endl;
    return 0;
}
