#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll x,k,d;
  cin >> x >> k >> d;
  x = abs(x);
 
  ll k1 = min(k,x/d);
  k -= k1;
  x -= k1 * d;
  if(k % 2 == 0){
      cout << x << endl;
  }
  else{
      cout << d-x << endl;
  }
  
}