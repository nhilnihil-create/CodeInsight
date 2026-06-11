#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  
  REP(i,n){
    cin >> h[i];
  }
  
  REP(i,n-1){
    if(h[n-i-2] <= h[n-i-1]) continue;
    else if(h[n-i-2]-h[n-i-1] == 1){
      h[n-i-2]--;
    }
    else{
      cout << "No" << endl;
      return 0;
    }
  }
    

    
  cout << "Yes" << endl;

        
    
}