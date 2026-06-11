#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  
  int ans = 0;
  int a = x / 500;
    
  ans += a * 1000;
  x -= a * 500;
  
  int b = x / 5;
  
  ans += b * 5;
  
  cout << ans << endl;
  
  
}