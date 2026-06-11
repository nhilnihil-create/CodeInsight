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

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
  bool ret = true;
  int n = S.length();

  for(int i=0; i<n/2; i++) {
    ret &= S[i] == S[n-(i+1)];
  }
  string ss = S.substr(0, (n-1)/2);
  for(int i=0; i<ss.length()/2; i++) {
    ret &= ss[i] == ss[ss.length()-(i+1)];
  }
  ss = S.substr((n+3)/2-1, n);
  for(int i=0; i<ss.length()/2; i++) {
    ret &= ss[i] == ss[ss.length()-(i+1)];
  }
  if(ret) std::cout << YES << std::endl;
  else std::cout << NO << std::endl;
}

int main(){
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}

