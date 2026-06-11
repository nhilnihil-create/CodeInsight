#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;
const int MAX_N = 1000000005;

vector<int> prime_factorize(int N){
  vector<int> ret;
  FOR(i, 2, sqrt(N) + 1){
    while(!(N % i)){
      ret.push_back(i);
      N /= i;
    }
  }
  if(N > 1) ret.push_back(N);
  return ret;
}

int main() {
  int N; cin >>N;
  vector<int> ans = prime_factorize(N);
  cout <<N <<":";
  REP(i, ans.size()) cout <<" " <<ans[i];
  cout <<endl;
  return 0;
}