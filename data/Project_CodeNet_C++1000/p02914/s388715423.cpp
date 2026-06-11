#include <bits/stdc++.h>
using namespace std;

const int MAX_ROW = 100000;  // 最大行数
const int MAX_COL = 60;  // 最大列数

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    explicit BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    bitset<MAX_COL>& operator[] (int i) {return val[i];}
    BitMatrix operator* (BitMatrix B) {
        BitMatrix A = *this;
        BitMatrix R(A.H, B.W);  // 答え
        BitMatrix tB(B.W, B.H);  // Bの転置行列
        for (int i = 0; i < tB.H; i++) {
            for (int j = 0; j < tB.W; j++) {
                tB[i][j] = B[i][j];
            }
        }
        for (int i = 0; i < R.H; i++) {
            for (int j = 0; j < R.W; j++) {
                R[i][j] = ((A[i] & tB[j]).count() & 1);
            }
        }
        return R;
    }
};
ostream& operator<<(ostream& s, BitMatrix A) {
    s << endl;
    for (int i = 0; i < A.H; i++) {
        for (int j = A.W - 1; j >= 0; j--) {
            if (j != A.W - 1) cout << " ";
            s << A[i][j];
        }
        s << endl;
    }
    return s;
}
BitMatrix pow(BitMatrix A, int64_t n) {
    BitMatrix R(A.H, A.H);
    for (int i = 0; i < A.H; i++) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}
// Gauss-Jordan の掃き出し法(BitMatrix版)
int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = A.W - 1; col >= 0; col--) {
        if (is_extended && col == 0) break;
        int pivot = -1;
        for (int row = rank; row < A.H; row++) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);  // 行交換
        // 掃き出し
        for (int row = 0; row < A.H; row++) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        rank++;
    }
    return rank;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    BitMatrix X(N, 60);
    int64_t a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        X.val[i] = (bitset<MAX_COL>) a;
    }
    bitset<MAX_COL> all_xor = 0;
    for (int i = 0; i < N; i++) {
        all_xor ^= X.val[i];
    }
    // all_xor が 0 になっている桁のみを考える
    for (int i = 0; i < N; i++) X.val[i] &= ~all_xor;

    GaussJordan(X);
    bitset<MAX_COL> bset = 0;
    for (int i = 0; i < N; i++) {
        bset ^= X.val[i];
    }
    uint64_t ret = bset.to_ullong() * 2 + all_xor.to_ullong();

    cout << ret << endl;

    return 0;
}
