#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
using u8t = std::uint64_t;
using i8t = std::int64_t;
using vi8t = std::vector<i8t>;
#define F3(I,A,B) for(i8t I=A,I##_N=B;I<I##_N;I++)
#define F(I,N) F3(I,0,N)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;

i8t mod_pow(u8t x,u8t y,u8t mod){
  u8t r=1;
  while (y){
    if(y&1)r=r*x%mod;
    y>>=1;
    x=x*x%mod;
  }
  return r;
}

int main() {
  u8t mod=1'000'000'007;
  R(N)R(K);

  //P(mod_pow(K,N,mod));

  vi8t Z(K+1);
  F3(i,1,K+1)
    Z[i]=mod_pow(K/i,N,mod);

  vi8t E(K+1);
  for(int i=K;i>=1;i--){
    i8t z=Z[i];
    for(int j=2;j<=K;j++){
      if(i*j>K)break;
      z += mod - E[i*j];
    }
    E[i]=z%mod;
  }

  i8t ans=0;
  F3(i,1,K+1){
    ans = (ans+i*E[i])%mod;
  }
  P(ans);
  return 0;
}
