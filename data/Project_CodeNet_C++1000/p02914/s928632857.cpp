#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int BIT_SZ = 60;
struct BitMatrix {
    int N, SZ;
    vector<bitset<BIT_SZ>> val;
    BitMatrix(int n = 1, int sz = BIT_SZ) : N(n), SZ(sz), val(n) { }
    bitset<BIT_SZ>& operator[](int i) { return val[i]; }
};
int gauss_jordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = A.SZ - 1; col >= 0; --col) {
        if (is_extended && col == A.SZ - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.N; ++row) {
            if (A[row][col]) { pivot = row; break; }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.N; ++row) {
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
    BitMatrix A(n);
    for (int d = 0; d < BIT_SZ; d++) {
        if (odd >> d & 1) continue;
        for (int i = 0; i < n; i++) if (a[i] >> d & 1) A[i][d] = 1;
    }
    gauss_jordan(A);
    bitset<BIT_SZ> even = 0;
    for (int i = 0; i < n; i++) even ^= A[i];
    cout << odd + even.to_ullong() * 2 << endl;
    return 0;
}