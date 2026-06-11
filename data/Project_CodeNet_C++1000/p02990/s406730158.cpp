#include<iostream>
#include<algorithm>
#include<vector>
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

// fact
template<typename INT>
struct factorial {
  std::vector<INT> fact, ifact;
  void init(int64_t N) {
    fact.resize(N+1); ifact.resize(N+1);
    fact[0] = fact[1] = INT(1);
    for(int i = 2; i <= N; ++i) fact[i] = fact[i-1]*i;
    ifact[N] = fact[N].inv();
    for(int i = N-1; i >= 0; --i) ifact[i] = ifact[i+1]*(i+1);
  }
  INT comb(int64_t n, int64_t k) { 
    if(k > n || k < 0) return INT(0);
    return fact[n]*ifact[k]*ifact[n-k];
  }
  INT hcomb(int64_t n, int64_t k) { return comb(n+k-1, k); }
};

int64_t const MOD = 1e9+7;
using mint = mod_int<MOD>;
factorial<mint> F;

int main() {
  int N, K; std::cin >> N >> K;
  F.init(N);
  for(int i = 1; i <= K; ++i) {
    std::cout << (F.hcomb(i, K-i)*F.hcomb(i+1, N-K-(i-1))).v_;
    std::cout << "\n";
  }
  return 0;
}
