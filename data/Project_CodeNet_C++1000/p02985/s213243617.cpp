#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

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

// fact
template<typename INT, int64_t MAXN_>
struct factorial {
  INT fact[MAXN_+1], ifact[MAXN_+1];
  void init(int64_t N) {
    fact[0] = fact[1] = INT(1);
    for(int i = 2; i <= N; ++i) fact[i] = fact[i-1]*i;
    ifact[N] = fact[N].inv();
    for(int i = N-1; i >= 0; --i) ifact[i] = ifact[i+1]*(i+1);
  }
  INT perm(int64_t n, int64_t k) {
    if(k > n) return INT(0);
    return fact[n]*ifact[n-k];
  }
};

int const MAXN = 1e5;

factorial<mint, MAXN> F;

int main() {
  int N, K; std::cin >> N >> K;
  F.init(K);
  std::vector<std::vector<int>> G(N);
  for(int i = 0; i < N-1; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  auto dfs = [&](auto&& f, int v, int p) -> mint {
    int adj = G[v].size();
    mint res = (p<0)? F.perm(K, adj+1): F.perm(K-2, adj-1);
    for(auto c: G[v]) if(c != p) res *= f(f, c, v);
    return res;
  };
  fin(dfs(dfs, 0, -1).v_);
  return 0;
}
