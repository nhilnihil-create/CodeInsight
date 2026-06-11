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
#define F(I,N) for(i8t I=0,I##_N=N;I<I##_N;I++)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;

struct infant{
  i8t opos;
  i8t active;
};

int main() {
  R(N)RV(A,N);
  std::vector<infant> arr;
  F(I,N){
    infant x;
    x.opos=I+1;
    x.active=A[I];
    arr.push_back(x);
  }
  std::sort(arr.begin(),arr.end(),[](auto const& a, auto const& b){return a.active > b.active;});

  i8t score=0;
  i8t left = 1, right = N;

  // scores[j] = (左端がj人埋まっている場合の最高得点)
  std::vector<i8t> scores;
  scores.push_back(0);
  std::vector<i8t> scores2;

  for (int i=0;i<N;i++){
    auto const& inf1 = arr[i];
    scores2.clear();
    scores2.push_back(0);
    for(int j=0;j<scores.size();j++){
      i8t l=1+j;
      i8t r=l+(N-i-1);
      auto const mvl = inf1.active*(inf1.opos - l);
      auto const mvr = inf1.active*(r - inf1.opos);
      scores2[j]=std::max(scores2[j],scores[j]+mvr);
      scores2.push_back(scores[j]+mvl);
    }
    scores.swap(scores2);
  }
  auto it = max_element(scores.begin(), scores.end());
  P(*it);
  return 0;
}
