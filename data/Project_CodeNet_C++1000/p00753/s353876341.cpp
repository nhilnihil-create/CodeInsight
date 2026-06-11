#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <cstring>

using namespace std;

#define REP(i, a, b) for(i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

vector<bool> isprime(123456*2+1, true);

void sieve(int n){
  int i, j;

  isprime[0] = isprime[1] = false;
  
  rep(i, n) if(isprime[i]){
    for(j = 2*i; j <= n; j += i) isprime[j] = false;
  }
  
  return;
}

int main(){
  int i, j;
  int n;
  int ret = 0;

  while(true){
    ret = 0;
    cin >> n;
    if(n == 0) break;
    
    sieve(2*n+1);
    
    REP(i, n+1, 2*n+1) if(isprime[i]) ret++;
    
    cout << ret << endl;
  }
  return 0;
}