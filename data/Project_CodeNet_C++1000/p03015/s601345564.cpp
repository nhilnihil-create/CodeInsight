#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
const long long MOD = 1000000007;
long long three_power[100001];
int main(void){
  string L;
  cin >> L;
  three_power[0] = 1;
  for(int i = 1; i < L.size(); i++){
    three_power[i] = (three_power[i - 1] * 3) % MOD;
  }
  long long ans = 0;
  long long tmp = 1;
  for(int i = 0; i < L.size(); i++){
    if(L[i] == '1'){
      ans = (ans + (tmp * three_power[L.size() - i - 1]) % MOD) % MOD;
      tmp = (tmp * 2) % MOD;
    }
  }
  ans = (ans + tmp) % MOD;
  cout << ans << endl;
  return 0;
}