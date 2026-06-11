#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <memory>
#include <array>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using point = complex<double_t>;
void print(const point p){
  cout<<real(p)<<' '<<imag(p)<<'\n';
}
const point rota = polar(1.0, M_PI/3.0);
void koch(const point first, const point last, size_t n){
  if(n==0) print(first);
  else{
    point mid1 = first+(last-first)/3.0;
    point mid3 = first+(last-first)*2.0/3.0;
    point mid2 = mid1+(mid3-mid1)*rota;
    koch(first, mid1, n-1);
    koch(mid1, mid2, n-1);
    koch(mid2, mid3, n-1);
    koch(mid3, last, n-1);
  }
}
int32_t main(){
  size_t n; cin>>n;
  const point first(0, 0), last(100, 0);
  koch(first, last, n);
  print(last);
}
