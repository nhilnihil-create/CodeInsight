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
using namespace std;

set <long long> get_divisors(long long N){
  set <long long> ret;
  if(N == 1){
    return ret;
  }
  ret.insert(N);
  if(N == 2){
    return ret;
  }
  for(long long i = 2; i < sqrt(N) + 1; i++){
    if(N % i == 0){
      ret.insert(i);
      ret.insert(N / i);
    }
  }
  return ret;
}
int main(){
  long long N;
  cin >> N;

  int ans = 0;
  set <long long> divisors1 = get_divisors(N);
  for(auto it = divisors1.begin(); it != divisors1.end(); it++){
    long long tmp = N;
    while(tmp % *it == 0){
      tmp /= *it;
    }
    if(tmp % *it == 1){
      ans ++;
    }
  }

  set <long long> divisors2 = get_divisors(N - 1);
  ans += divisors2.size();
  cout << ans << endl;
  return 0;
}
