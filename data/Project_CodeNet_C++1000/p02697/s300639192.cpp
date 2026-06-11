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
using u8t = std::uint64_t;
using i8t = std::int64_t;
#define F(I,N) for(i8t I=0,I##_N=N;I<I##_N;I++)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;
int main() {
  R(N)R(M);
  int c=0;
  int n=(N-1)/2;
  int a=1,b=n;//蟾ｮn-1
  while (a<b) {
    std::cout<<a<<" "<<b<<std::endl;
    if(++c==M)return 0;
    a++;b--;
  }

  a=n+1,b=2*n+1;//蟾ｮn
  while (a<b) {
    std::cout<<a<<" "<<b<<std::endl;
    if(++c==M)return 0;
    a++;b--;
  }
  return 0;
}
