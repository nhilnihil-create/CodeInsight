#include<iostream>
#include<string>
#include<cstdint>
#include<alloca.h>

int64_t const MOD = 1e9+7;
std::string L;
int64_t const tbl[] = {1, 3, 5, 9, 11, 15, 19, 27, 29, 33, 37, 45, 49, 57, 65, 81};

int to_num(int k, char const* p) {
  int res = 0;
  while(--k>=0) { res = res*2 + (*p++ - '0'); }
  return res;
}

bool is_zero(int k, char const* p) {
  while(--k>=0) if(*p++ != '0') return false;
  return true;
}

void minus1(int k, char const* p, char *o) {
  int i = k-1;
  for(; i >= 0; --i) {
    if(p[i] == '0') o[i] = '1';
    else {
      o[i] = '0';
      --i;
      break;
    }
  }
  for(; i >= 0; --i) o[i] = p[i];
}

int64_t full(int k) {
  int64_t res = 1;
  while(--k>=0) (res *= 3) %= MOD;
  return res;
}

int64_t count_bits_pow2(int k, char const*p) {
  int64_t res = 1;
  while(--k>=0) if(*p++ != '0') (res *= 2) %= MOD;
  return res;
}

int64_t calc(int k, char const* p) {
  if(k <= 4) return tbl[to_num(k, p)];
  int l = k/2, r = k - l;
  if(is_zero(l, p)) return calc(r, p+l);
  char *p1 = (char*)alloca(l);
  minus1(l, p, p1);
  int64_t resL = calc(l, p1)*full(r)%MOD;
  int64_t resR = count_bits_pow2(l, p)*calc(r, p+l)%MOD;
  return (resL+resR)%MOD;
}

int main() {
  std::cin >> L;
  std::cout << calc(L.size(), L.c_str()) << std::endl;
  return 0;
}
