#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  vector<int> a(5);
  REP(i,5) cin >> a[i];
  
  REP(i,5){
    if(a[i] == 0){
      cout << i+1 << endl;
      return 0;
    }
  }
    
  

}