#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k; 
  cin >> n >> k;
  
  int ans = 0;
  ll b = 1;
  REP(i,50){
    if(b > n){
      break;
    }
    b *= k;
    ans++;
  }
  
  cout << ans << endl;
}