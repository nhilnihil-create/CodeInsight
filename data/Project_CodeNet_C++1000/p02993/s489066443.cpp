#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  rep(i, s.size()-1) {
    if(s[i] == s[i+1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  
  cout << "Good" << endl;
  return 0;
}
