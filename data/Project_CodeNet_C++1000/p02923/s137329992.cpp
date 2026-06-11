#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int ans = 0;
  int sum = 0;
  int h1;
  cin >> h1;
  REP(i,n-1){
    int h2;
    cin >> h2;
    if(h1 >= h2){
      sum++;
    }
    else sum = 0;
    
    ans = max(sum,ans);
    h1 = h2;
  }
  
  cout << ans << endl;
  
}