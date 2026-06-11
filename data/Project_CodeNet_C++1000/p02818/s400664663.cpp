#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
 
  if(a >= k){
    cout << a-k << " " << b << endl;
    return 0;
  }
  else if((a+b) >= k){
    cout << 0 << " " << b - (k - a) << endl;
    return 0;
  }
  else{
    cout << 0 << " " << 0 << endl;
    return 0;
  }

  
}