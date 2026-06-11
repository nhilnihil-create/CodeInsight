//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  string s;
  cin >> s;
  string tmp = "AB";
  int cnt = 0;
  
  for (int i = 0; i < s.size(); i++) {
    
    for (int j = 1; j <= s.size(); j++) {
      
      if (s.substr(i, j) != tmp) {
        cnt++;
        tmp = s.substr(i, j);
        i = i+j-1;
        break;
      }
    }
  }
  
  
  cout << cnt << endl;
  return 0;
}