#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string s;
  cin >> s;
  
  int n = s.size();
  
  bool ans = true;
  
  REP(i,n) {
    if (i % 2 == 0 && s[i] == 'L') ans = false;
    if (i % 2 == 1 && s[i] == 'R') ans = false;
  }
  
  cout << (ans ? "Yes" : "No") << endl;
     
}