#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  
  ll int point = 0;
  for(char x : t) {
    if(x == 'r') point += p;
    else if(x == 's') point += r;
    else point += s;
//    cout << point << endl;
  }
  
//  cout << point << endl;
  
  for(int i = k; i < n; ++i) {
    if(t[i] == t[i-k]) {
      char w = t[i];
      if(w == 'r') point -= p;
      else if(w == 's') point -= r;
      else point -= s;
      t[i] = 'o';
    }
  }
  
  cout << point << endl;
  
    
  return 0;
}
