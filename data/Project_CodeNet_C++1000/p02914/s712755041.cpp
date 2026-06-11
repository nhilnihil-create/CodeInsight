#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAX_ROW = 1e5;    // to be set appropriately
const int MAX_COL = 60;    // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) { }
    bitset<MAX_COL>& operator[](int i) { return val[i]; }
};
int gauss_jordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = A.W - 1; col >= 0; --col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) { pivot = row; break; }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto &ai: a) cin >> ai;
    long long odd = 0;
    for (int i = 0; i < n; i++) odd ^= a[i];
    BitMatrix A(n, 60);
    for (int d = 0; d < 60; d++) {
        if (odd >> d & 1) continue;
        for (int i = 0; i < n; i++) if (a[i] >> d & 1) A[i][d] = 1;
    }
    gauss_jordan(A);
    bitset<60> even = 0;
    for (int i = 0; i < n; i++) even ^= A[i];
    cout << odd + even.to_ullong() * 2 << endl;
    return 0;
}