#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  
  int b,c = 0;
  
  REP(i,m){
    cin >> b;
    c += b;
  }

  if(n >= c) cout << n-c << endl;
  else cout << -1 << endl;
  
  
}