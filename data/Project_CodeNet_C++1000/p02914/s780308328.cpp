#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

// Bit Matrix
const int MAX_ROW = 110000; // to be set appropriately
const int MAX_COL = 60; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};
 
// 掃き出し法
void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H, 0);
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = 0; row < A.H; ++row) {
            if (used[row]) continue;
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        for (int row = 0; row < A.H; ++row) {
            if (row != pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = true;
    }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vll a(n);
  ll x = 0;
  for(int i=0;i<n;++i) {
    cin >> a[i];
    x ^= a[i];
  }

  for(int i=0;i<n;++i) {
    for(int j=0;j<60;++j) {
      a[i] &= (((1ll<<60)-1) ^ x);
    }
  }

  BitMatrix A(n, 60);
  for(int i=0;i<n;++i) {
    ll tmp = 0;
    for(int j=0;j<60;++j) {
      tmp += ((a[i]>>j)&1)<<(59-j);
    }
    A[i] = bitset<MAX_COL>(tmp);
  }

  GaussJordan(A);
  ll add = 0;
  for(int i=0;i<n;++i) {
    ll tmp = 0;
    //cout << A[i] << endl;
    for(int j=0;j<60;++j) {
      tmp *= 2;
      tmp += A[i][j];
    }
    //cout << tmp << endl;
    add ^= tmp;
  }
  cout << x + add * 2 << endl;


}
