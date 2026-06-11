#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<bool> checked(n,false);
  REP(i,n) cin >> s[i];
  sort(s.begin(), s.end());
  
  
  int sn = 1;
  int x = 1;
  for (int i = 1; i < (n); ++i){
      if(s[i-1] == s[i]){
        x++;
      }
      else{
        x = 1;
      }
    sn = max(x,sn);
  }

  
  x = 1;
  for (int i = 1; i < (n); ++i){
      if(s[i-1] == s[i]){
        x++;
      }
      else{
        x = 1;
      }
    if(x == sn){
      checked[i-1] = true;
    }
    if(sn == 1){
      checked[i] = true;
    }
  }  
  
  REP(i,n){
    if(checked[i]){
	  cout << s[i] << endl;
    }
  }

      
}