#include <algorithm>
#include <vector>
#include <cfloat>
#include <string>
#include <cmath>
#include <set>
#include <cstdlib>
#include <map>
#include <ctime>
#include <iomanip>
#include <functional>
#include <deque>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
#include <climits>
#include <sys/time.h>
#include <cctype>

using namespace std;

typedef long long ll;

int main() {
  bool notPrime[123456*2+1];
  memset(notPrime, false, sizeof(notPrime));
  for (int i = 2; i*i <= 123456*2; i++) {
    for (int j = i+i; j <= 123456*2; j+=i) {
      notPrime[j] = true;
    }
  }
  notPrime[0] = true;
  notPrime[1] = true;
  int memo[123456*2+1];
  memo[0] = 0;
  for (int i = 1; i <= 123456*2; i++) {
    memo[i] = memo[i-1]+!notPrime[i];
  }
  int n;
  while(true) {
    cin >> n;
    if (n == 0) break;
    std::cout << memo[2*n]-memo[n] << std::endl;
  }
}