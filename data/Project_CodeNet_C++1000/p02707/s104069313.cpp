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
  int N;
  cin >> N;
  vec<int> A(N+1, 0);
  int t;
  for(int i = 0; i < N-1; i++){
    cin >> t;
    A[t]++;
  }
  for(int i = 1; i <= N; i++){
    cout << A[i] << endl;
  }

  return 0;
}
