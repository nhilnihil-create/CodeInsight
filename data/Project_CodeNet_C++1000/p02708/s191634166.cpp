/* include c++ libraries */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

/* include c-lang libraries */
#include <climits>
#include <cmath>

/* include my libraries */
//#include <show_vec.hh>

using namespace std;

#define LINE DEBUG{ printf("LINE : %d\n", __LINE__); }
#define DEBUG if(false)

using ll = long long;
template<class T> using vec = vector<T>;

const int MOD = 1000000007;

int main(){
  ll N, K;
  cin >> N >> K;

  ll Ans = 1;;
  ll min = N*(N+1)/2;
  ll max = N*(N+1)/2;
  for(int i = 0; i < N-K+1; i++){
    min = min - (N-i);
    max = max - i;
    Ans = (Ans + (max-min+1)) % MOD;
  }

  cout << Ans << endl;

  return 0;
}
