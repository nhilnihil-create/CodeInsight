#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> vec;
  
  int n = s.size();
  int lastcut = 0;
  for(int i = 1; i < n; ++i) {
    if(s[i-1] == 'L' && s[i] == 'R') { 
      vec.push_back(s.substr(lastcut, i-lastcut));
      lastcut = i;
    }
  }
  vec.push_back(s.substr(lastcut, n-lastcut));
  
  for(string x : vec) {
    int r = 0; int l = 0;
    for(char y : x) {
      if(y == 'R') ++r;
      else ++l;
    }
    
    int left = (r+1)/2 + l/2;
    int right = r/2 + (l+1)/2;
    rep(i, r-1) cout << "0 ";
    cout << left << " " << right << " ";
    rep(i, l-1) cout << "0 ";
  }
  
  return 0;
}
