#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int mn(vector<int> &x, int n, int b){
    
  if(b == 100) return 100000000;
  
  int y = 0;
  REP(i,n){
      y += (x[i] - b) * (x[i] - b);
  }

  
  return min(mn(x,n,b+1),y);
}
  

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  REP(i,n) cin >> x[i];
  
  int b = 0;


  
  cout << mn(x,n,b) << endl;
  
}
