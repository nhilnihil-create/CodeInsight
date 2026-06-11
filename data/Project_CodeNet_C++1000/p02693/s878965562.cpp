#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int k,a,b;
  cin >> k >> a >> b;
  bool can = false;
  while(a <= b){
    if(a % k == 0){
      can = true;
    }
    a++;
  }
  
  if(can) cout << "OK" << endl;
  else cout << "NG" << endl;
      
}