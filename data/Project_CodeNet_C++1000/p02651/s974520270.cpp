#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_ROW = 510;  // to be set appropriately
const int MAX_COL = 64;   // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL> &operator[](int i) { return val[i]; }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
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

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row)
        if (M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}

int main() {
    int T;
    cin >> T;
    vector<bool> ans(T, true);
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<bitset<MAX_COL>> A(N);
        string S;
        for (int i = 0; i < N; i++) {
            unsigned long long val;
            cin >> val;
            A.at(i) = bitset<MAX_COL>(val);
        }
        cin >> S;
        BitMatrix m(N, 64);
        int r = 0;
        for (int i = N - 1; i >= 0; i--) {
            m[r] = A[i];
            int rank = GaussJordan(m);
            if (r < rank) {
                if (S[i] == '1') {
                    ans[t] = false;
                    break;
                }
                r = rank;
            }
        }
    }
    for (auto b : ans) {
        if (b) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}
