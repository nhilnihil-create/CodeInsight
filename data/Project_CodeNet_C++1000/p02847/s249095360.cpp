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
  string s;
  cin>>s;
  if(s=="SUN")
    std::cout << 7 << std::endl;
  else if(s=="MON")
    std::cout << 6 << std::endl;
  else if(s=="TUE")
    std::cout << 5 << std::endl;
  else if(s=="WED")
    std::cout << 4 << std::endl;
  else if(s=="THU")
    std::cout << 3 << std::endl;
  else if(s=="FRI")
    std::cout << 2 << std::endl;
  else
    std::cout << 1 << std::endl;
  return 0;
}
