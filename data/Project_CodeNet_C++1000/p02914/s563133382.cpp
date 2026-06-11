#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// http://drken1215.hatenablog.com/entry/2019/03/20/202800
const int MAX_ROW = 60; // to be set appropriately
const int MAX_COL = 100005; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
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
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll all_xor = 0;
    ll all_or = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all_xor ^= a[i];
        all_or |= a[i];
    }

    ll red = 0;
    vector<int> b;
    BitMatrix A(0, n);
    for (int i = 59; i >= 0; i--) {
        if (all_xor & (1LL << i)) {
            continue;
        }

        if (!(all_or & (1LL << i))) {
            continue;
        }

        b.push_back(1);
        for (int j = 0; j < n; j++) {
            if (a[j] & (1LL << i)) {
                A[A.H].set(j);
            }
        }
        A.H++;

        vector<int> res;
        int rank = linear_equation(A, b, res);
        if (rank == -1) b.back() = 0;
        else {
            red ^= (1LL << i);
        }
    }
    cout << (red + (all_xor ^ red)) << "\n";
    return 0;
}