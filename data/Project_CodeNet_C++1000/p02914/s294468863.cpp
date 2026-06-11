#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#pragma warning(disable : 4996)

typedef long long ll;
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;

const int MAX_ROW = 62;      // to be set appropriately
const int MAX_COL = 100010;  // to be set appropriately
struct BitMatrix {
  int H, W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int m = 1, int n = 1)
      : H(m), W(n) {
  }
  inline bitset<MAX_COL>& operator[](int i) {
    return val[i];
  }
};

ostream& operator<<(ostream& s, BitMatrix A) {
  s << endl;
  for (int i = 0; i < A.H; ++i) {
    for (int j = 0; j < A.W; ++j) {
      s << A[i][j] << ", ";
    }
    s << endl;
  }
  return s;
}

inline BitMatrix operator*(BitMatrix A, BitMatrix B) {
  BitMatrix R(A.H, B.W);
  BitMatrix tB(B.W, B.H);
  for (int i = 0; i < tB.H; ++i)
    for (int j = 0; j < tB.W; ++j) tB[i][j] = B[j][i];
  for (int i = 0; i < R.H; ++i)
    for (int j = 0; j < R.W; ++j) R[i][j] = ((A[i] & tB[j]).count() & 1);
  return R;
}

inline BitMatrix pow(BitMatrix A, long long n) {
  BitMatrix R(A.H, A.H);
  for (int i = 0; i < A.H; ++i) R[i][i] = 1;
  while (n > 0) {
    if (n & 1) R = R * A;
    A = A * A;
    n >>= 1;
  }
  return R;
}

int GaussJordan(BitMatrix& A, bool is_extended = false) {
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

int linear_equation(BitMatrix A, vector<int> b, vector<int>& res) {
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

int main(int argc, char* argv[]) {
  int n;
  scanf("%d", &n);

  int sum[60] = {0};  // 各bitについて1が立っている個数を合計する
  vector<int> z[60];
  int i, k;
  for (i = 0; i < n; i++) {
    ll tmp;
    scanf("%lld", &tmp);
    for (k = 0; k < 60; k++) {
      if (tmp & ((ll)1 << k)) {
        z[k].push_back(i);
        sum[k]++;
      }
    }
  }

  vector<int> aa;  // 1が立っている個数が偶数で、それを奇数と奇数に分けるbitを保持
  ll ans = 0;
  for (i = 59; i >= 0; i--) {
    if (sum[i] % 2) {
      ans += ((ll)1 << i);
    } else if (sum[i] > 0) {
      aa.push_back(i);
      int siz = (int)aa.size();
      BitMatrix A(siz, n);
      int j, k;
      for (j = 0; j < siz; j++) {
        for (k = 0; k < (int)z[aa[j]].size(); k++) {
          A[j][z[aa[j]][k]] = 1;
        }
      }
      vector<int> b(siz, 1);
      vector<int> res;
      int rk = linear_equation(A, b, res);
      if (rk >= 0) {
        ans += ((ll)1 << i) * 2;
      } else {
        aa.pop_back();
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}
