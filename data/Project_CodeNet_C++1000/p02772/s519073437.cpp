#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n; 
  cin >> n;
  
  bool ok = true;
  REP(i,n){
    int a;
    cin >> a;
    if(a % 2 == 0){
      if(a % 3 != 0 && a % 5 != 0){
        ok = false;
      }
    }
  }
  
  if(ok) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;

  
  
}