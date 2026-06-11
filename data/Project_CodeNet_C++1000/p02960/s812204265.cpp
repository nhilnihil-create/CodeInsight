#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXLS = 1e5;

// mint
#include<cstdint>
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

mint dp[MAXLS][13];

int main() {
  std::string S; std::cin >> S; std::reverse(S.begin(), S.end());
  dp[0][0] = 1;
  for(int i = 0, m = 1; i < S.size(); ++i, m=(m*10)%13) {
    char c = S[i];
    if(c == '?') {
      for(int j = 0; j < 13; ++j) {
        for(int k = 0; k < 10; ++k) dp[i+1][(j+k*m)%13] += dp[i][j];
      }
    } else {
      int d = c - '0';
      for(int j = 0; j < 13; ++j) dp[i+1][(j+d*m)%13] = dp[i][j];
    }
  }
  fin(dp[S.size()][5].v_);
  return 0;
}
