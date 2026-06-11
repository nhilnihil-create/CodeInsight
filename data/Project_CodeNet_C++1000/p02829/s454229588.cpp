#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll a,b;
  cin >> a >> b;
 
  REP(i,3){
    if(i+1 != a && i+1 != b){
      cout << i+1 << endl;
      return 0;
    }
  }

  
}