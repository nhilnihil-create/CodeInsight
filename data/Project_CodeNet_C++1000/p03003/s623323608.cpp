#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// mint
template<int64_t Prime>
struct mod_int {
  int64_t v_;
  mod_int(int64_t x=0) : v_(x) { normalize(); }
  void normalize() { ((v_ %= Prime) += Prime) %= Prime; }
  mod_int operator+=(mod_int const& r){ (v_ += r.v_) %= Prime; return *this; }
  mod_int operator-=(mod_int const& r){ (v_ += Prime - r.v_) %= Prime; return *this; }
  mod_int operator*=(mod_int const& r){ (v_ *= r.v_) %= Prime; return *this; }
  mod_int operator+(mod_int const& r) { mod_int res(*this); return res += r; }
  mod_int operator-(mod_int const& r) { mod_int res(*this); return res -= r; }
  mod_int operator*(mod_int const& r) { mod_int res(*this); return res *= r; }
  mod_int pow(int x) const {
    int64_t res = 1, v = v_;
    while(x > 0) {
      if(x&1) (res *= v) %= Prime;
      x/=2; (v *= v) %= Prime;
    }
    return mod_int(res);
  }
  mod_int inv() const { return pow(Prime-2); }
};

int64_t const MOD = 1e9+7;
typedef mod_int<MOD> mint;

int main() {
  int N, M; std::cin >> N >> M;
  std::vector<int> S(N), T(M);
  for(int i = 0; i < N; ++i) std::cin >> S[i];
  for(int i = 0; i < M; ++i) std::cin >> T[i];
  std::vector<std::vector<mint>> sum(N+1, std::vector<mint>(M+1));
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      mint tmp = sum[i][j+1] + sum[i+1][j];
      if(S[i] == T[j]) sum[i+1][j+1] = tmp+1;
      else sum[i+1][j+1] = tmp - sum[i][j];
    }
  }
  fin((sum[N][M]+1).v_);
  return 0;
}
