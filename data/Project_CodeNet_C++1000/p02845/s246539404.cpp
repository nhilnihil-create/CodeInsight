#include<iostream>
#include<algorithm>
#include<cstdint>
#include<map>

int64_t const MOD = 1e9+7;

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
typedef mod_int<MOD> mint;

int main() {
  int N; std::cin >> N;
  std::map<std::pair<int,int>,mint> s;
  int x = 0, y = 0, z = 0;
  mint ans(1);
  for(int i = 0; i < N; ++i) {
    int A; std::cin >> A;
    std::map<std::pair<int,int>,mint> n;
    int c = 0;
    if(A == x) ++c;
    if(A == y) ++c;
    if(A == z) ++c;
    ans *= mint(c);
    if(A == x) ++x;
    else if(A == y) ++y;
    else ++z;
    if(x > y) std::swap(x, y);
    if(x > z) std::swap(x, z);
    if(y > z) std::swap(y, z);
  }
  std::cout << ans.v_ << std::endl;
  return 0;
}
