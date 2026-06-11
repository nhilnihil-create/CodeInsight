#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c; 
  cin >> a >> b >> c;
  
  if(a == b && b == c) cout << "No" << endl;
  else if(a == b || a == c || b == c) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  
  
}