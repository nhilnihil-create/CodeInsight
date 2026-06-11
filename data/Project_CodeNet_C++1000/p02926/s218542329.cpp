#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cmath>
#include <complex>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;



int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::vector<std::complex<int>> engine;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    engine.push_back(std::complex<int64_t>(x,y));
  }
  std::sort(engine.begin(), engine.end(),[](const std::complex<int64_t>& a,const std::complex<int64_t>& b)->bool{
    std::complex<double> ca(a.real(),a.imag()),cb(b.real(),b.imag());
    return std::arg(ca)<std::arg(cb);
  });
  for(int i=0;i<n;i++){
    engine.push_back(engine[i]);
  }

  // for(auto e:engine){
  //   std::complex<double> ca(e.real(),e.imag());
  //   cerr<<std::arg(ca)<<endl;
  // }

  double result=0;
  for(int front=0;front<n;front++){
    for(int back=front;back-front<n;back++){
      double tmp=0;
      int64_t x=0,y=0;
      for(int i=front;i<=back;i++){
        x+=engine[i].real();
        y+=engine[i].imag();
      }
      tmp=sqrt(x*x+y*y);
      result=std::max(result,tmp);
    }
  }
  cout<<result<<endl;

  return 0;
}
