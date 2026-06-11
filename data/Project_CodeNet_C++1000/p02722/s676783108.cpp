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
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;
using i8t = std::int64_t;
using vi8t = std::vector<i8t>;
using vvi8t = std::vector<std::vector<i8t>>;
static const i8t i8t_max=numeric_limits<i8t>::max();
static const i8t i8t_min=numeric_limits<i8t>::min();
using u8t = std::uint64_t;
using vu8t = std::vector<u8t>;
#define F3(I,A,B) for(i8t I=A,I##_N=B;I<I##_N;I++)
#define F(I,N) F3(I,0,N)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;
template<typename T> T umax(T& ans,T const& value) {if(value>ans)ans=value;return ans;}
template<typename T> T umin(T& ans,T const& value) {if(value<ans)ans=value;return ans;}

std::vector<std::pair<u8t,u8t>> prime_multifactors(u8t value){
  std::vector<std::pair<u8t,u8t>> factors;
  if(value==0){factors.emplace_back(0,1);return factors;}
  auto _reduce = [&](auto f){
    if(value%f)return;
    value/=f;factors.emplace_back(f,1);
    while(value%f==0){value/=f;factors.back().second++;}
  };
  _reduce(2);
  _reduce(3);
  for (i8t i=5;i*i<=value;i+=6){
    if(i*i>value)break;
    _reduce(i);
    _reduce(i+2);
  }
  if(value!=1)factors.emplace_back(value,1);
  return factors;
}

vu8t prime_divisors(u8t value){
  auto facm = prime_multifactors(value);
  vi8t ind(facm.size()+1,0);
  int depth=0;
  u8t K=1;
  vu8t divisors;
  while (1){
    if(depth<facm.size()&&ind[depth]<=facm[depth].second){
      depth++;
    }else{
      if(depth==facm.size()){
        divisors.push_back(K);
      }

      do{
        while(ind[depth]){
          K/=facm[depth].first;
          ind[depth]--;
        }
        depth--;
        if(depth<0)return divisors;
      }while(ind[depth]==facm[depth].second);

      ind[depth]++;
      K*=facm[depth].first;
    }
  }
}

//-----------------------------------------------------------------------------

bool test1(i8t N,i8t K){
  while(N&&N%K==0)N/=K;
  return N%K==1;
}

int main() {
  R(N);
  i8t ans=prime_divisors(N-1).size()-1;
  for(auto K:prime_divisors(N)){
    if(K==1)continue;
    if(test1(N,K))ans++;
  }
  P(ans);
  return 0;
}
