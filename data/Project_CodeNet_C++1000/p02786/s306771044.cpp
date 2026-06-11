#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll h;
  cin >> h;
  ll x = 1,y = 1;
  
  while(1){
    
    h /= 2;
    x += y;
    y *= 2;
    
    if(h < 1) break;
    
  }
  
  cout << x-1 << endl;
  
}
