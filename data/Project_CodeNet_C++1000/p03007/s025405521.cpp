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

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, std::vector<long long> A){
  sort(A.begin(), A.end());
  vector<pair<ll, ll>> v;
  for(ll i=1; i+1<N; i++) {
    if(A[i]<0) {
      v.push_back(make_pair(A[N-1], A[i]));
      A[N-1] = A[N-1]-A[i];
    } else {
      v.push_back(make_pair(A[0], A[i]));
      A[0] = A[0] - A[i];
    }
  }
  v.push_back(make_pair(A[N-1], A[0]));
  std::cout << A[N-1]-A[0] << std::endl;
  for(auto p: v) {
    std::cout << p.first << " " << p.second << std::endl;
  }
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

