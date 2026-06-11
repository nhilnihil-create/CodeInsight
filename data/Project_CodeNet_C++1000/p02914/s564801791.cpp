#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) { return std::vector<T>(n, std::forward<T>(val)); }
template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}
template<class Cond> struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  template<class T> bool operator()(T& a, const T& b) const { if(cond(a, b)) { a = b; return true; } return false; }
};
template<class Cond> chain<Cond> make_chain(Cond cond) { return chain<Cond>(cond); }

#include <bitset>
#include <array>
#include <vector>

template<const int H, const int W>
struct bit_matrix {
  std::array<std::bitset<W>, H> m;

  bit_matrix(){} 

  std::bitset<W>& operator[](int i) { return m[i]; }
  const std::bitset<W>& operator[](int i) const { return m[i]; }

  template<const int X>
  bit_matrix<H, X> operator*(const bit_matrix<W, X>& r) const {
    bit_matrix<H, X> ans;
    bit_matrix<X, W> tr;
    for(int i = 0;i < W;i++) for(int j = 0;j < X;j++) {
      if(r[i][j]) tr[j].set(i);
    }
    for(int i = 0;i < H;i++) for(int j = 0;j < X;j++) {
      ans[i][j] = (m[i] & tr[j]).count() & 1;
    }
    return ans;
  }
};

template<const int H, const int W>
std::vector<int> gauss_jordan(bit_matrix<H, W>& A, bool is_extended = false) {
  int rank = 0;
  std::vector<int> fst;
  for(int j = 0; j < W; j++) {
    if(is_extended && j + 1 == W) break;
    int pivot = -1;
    for(int i = rank; i < H; i++) {
      if(A[i].test(j)) {
        pivot = i;
        break;
      }
    }
    if(pivot == -1) continue;
    std::swap(A[rank], A[pivot]);
    for(int i = 0;i < H; i++) {
      if(i != rank && A[i][j]) {
        A[i] ^= A[rank];
      }
    }
    fst.push_back(j);
    rank++;
  }
  return fst;
}

const int H_MAX = (int)(101010);
const int W_MAX = 62;

int main() {
  i64 N;
  cin >> N;
  vector<i64> A(N);
  i64 sum = 0;
  rep(i,0,N) {
    cin >> A[i];
    sum ^= A[i];
  }
  i64 ans = 0;
  vector<i64> bit;
  rep(i,0,61) {
    if(sum & (1ll << i)) {
      ans += (1ll << i);
    }
    else {
      bit.push_back(i);
    }
  }
  reverse(all(bit));

  bit_matrix<H_MAX, W_MAX> mat;
  rep(i,0,N) {
    rep(j,0,bit.size()) {
      mat[i][j] = !!(A[i] & (1ll << bit[j]));
    }
  }
  auto ranks = gauss_jordan(mat);
  i64 res = 0;
  for(int i = 0;i < ranks.size();i++) {
    i64 x = 0;
    rep(j,0,bit.size()) {
      if(mat[i][j]) {
        x ^= (1ll << bit[j]);
      }
    }
    res = std::max(res, res ^ x);
  }
  cout << (ans + (res * 2)) << endl;
}
