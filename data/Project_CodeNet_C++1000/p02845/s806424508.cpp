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

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A){
  ll c[3] = {0};
  ll ans = 1;
  for(auto x: A) {
    ll cnt = 0;
    for(ll i=0; i<3; i++) {
      if(c[i]==x) {
	if(cnt==0) {
	  c[i]++;
	}
	cnt++;
      }
    }
    ans = (ans * cnt) % MOD;
    // std::cout << cnt <<": ";
    // for(ll i=0; i<3; i++)
    //   std::cout << c[i] << " ";
    // std::cout << std::endl;
  }
  std::cout << ans << std::endl;
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

