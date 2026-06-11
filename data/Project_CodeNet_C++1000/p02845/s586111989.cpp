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

void add(int x, int y, int z, std::map<std::pair<int,int>,mint>&s, mint v) {
  if(x > y) std::swap(x, y);
  if(x > z) std::swap(x, z);
  if(y > z) std::swap(y, z);
  s[std::make_pair(x,y)] += v;
}
int main() {
  int N; std::cin >> N;
  std::map<std::pair<int,int>,mint> s;
  s[std::make_pair(0,0)] = mint(1);
  for(int i = 0; i < N; ++i) {
    int A; std::cin >> A;
    std::map<std::pair<int,int>,mint> n;
    for(auto p: s) {
      int x = p.first.first, y = p.first.second, z = i - x - y;
      if(A == x) add(x+1, y, z, n, p.second);
      if(A == y) add(x, y+1, z, n, p.second);
      if(A == z) add(x, y, z+1, n, p.second);
    }
    s.swap(n);
  }
  mint ans;
  for(auto p: s) ans += p.second;
  std::cout << ans.v_ << std::endl;
  return 0;
}
