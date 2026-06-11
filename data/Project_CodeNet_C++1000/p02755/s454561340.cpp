#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b;
  cin >> a >> b;
  
  int ans = -1;
  REP(i,10000){
    int c = i * 0.08;
    int d = i * 0.1;
    if(c == a && d == b){
	  ans += i+1;
      break;
    }
    else{
      continue;
    }
  }
  
  cout << ans << endl;

}