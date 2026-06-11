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

template<typename T>
void arr_print(T arr){
  int i=0;
  for(auto x:arr){if(i++)std::cout<<" ";std::cout<<x;}
  std::cout<<std::endl;
}

int main() {
  R(N)R(K)R(C)RL(_)RL(S);
  vi8t early(K), late(K);

  int k=0;
  for(int i=0;i<N;i++){
    if(S[i]!='x'){
      if(k==K)return 0; // K+1日以上働けるのでいつでも休める。
      early[k++]=i;
      i+=C;
    }
  }

  k=K;
  for(i8t i=N-1;i>=0;i--){
    if(S[i]!='x'){
      late[--k]=i;
      i-=C;
    }
  }

  F(k,K)if(early[k]==late[k])P(early[k]+1);

  return 0;
}
