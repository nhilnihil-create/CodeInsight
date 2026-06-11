#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;
  
  n %= k; 
  while(1){
    if(n > abs(n-k)){
    n = abs(n-k);
    }
    else break;
  }
  
  cout << n << endl;
    
  
}