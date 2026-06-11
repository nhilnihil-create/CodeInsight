#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,a,b; 
  cin >> n;
  int ans = 0;
  
  if(n % 2 == 0) ans += n/2;
  else ans += n/2 + 1;
  
  cout << ans << endl;
  
}