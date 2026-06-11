#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

int main(){
  ll n, k, s;
  cin>>n>>k>>s;
  rep(i,k) std::cout << s << ' ';
  if(k==n) return 0;
  if (s == 1000000000) {
    rep(i,n-k-1) std::cout << s-1 << ' ';
    std::cout << s-1 << std::endl;
  } else {
    rep(i,n-k-1) std::cout << s+1 << ' ';
    std::cout << s+1 << std::endl;
  }
  return 0;
}
