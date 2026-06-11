#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;


int main() {
  int k;
  cin >> k;
  

  int n = 7;
  
  REP(i,k){
    if(n % k == 0){
      cout << i+1 << endl;
      return 0;
    }
    n %= k;
    n *= 10;
    n += 7;
  }
  cout << -1 << endl;
  
  
}