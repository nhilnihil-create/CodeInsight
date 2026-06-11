#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<int64_t Prime>
struct mod_int {
  int64_t v_;
  mod_int(int64_t x=0) : v_(x) { normalize(); }
  void normalize() { ((v_ %= Prime) += Prime) %= Prime; }
  mod_int operator+=(mod_int const& r){ (v_ += r.v_) %= Prime; return *this; }
  mod_int operator-=(mod_int const& r){ (v_ += Prime - r.v_) %= Prime; return *this; }
  mod_int operator*=(mod_int const& r){ (v_ *= r.v_) %= Prime; return *this; }
  mod_int operator+(mod_int const& r) const { mod_int res(*this); return res += r; }
  mod_int operator-(mod_int const& r) const { mod_int res(*this); return res -= r; }
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
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string L; std::cin >> L;
  std::vector<mint> dpN(L.size()), dpT(L.size());
  dpN[0] = 1;
  dpT[0] = 2;
  for(int i = 1; i < L.size(); ++i) {
    if(L[i] == '0') {
      dpT[i] = dpT[i-1];
      dpN[i] = dpN[i-1]*3;
    } else {
      dpT[i] = dpT[i-1]*2;
      dpN[i] = dpT[i-1] + dpN[i-1]*3;
    }
  }
  mint ans = dpT[L.size()-1] + dpN[L.size()-1];
  fin(ans.v_);
  return 0;
}
