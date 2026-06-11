#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int cnt = 0;
  REP(i,n-2){
    if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
      cnt++;
    }
  }
  
  cout << cnt << endl;

  
}