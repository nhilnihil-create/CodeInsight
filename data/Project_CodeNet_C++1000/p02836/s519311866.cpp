#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;

  for (int i = 0; i < s.size(); i++){
    if(s[i] != s[s.size() - i - 1]){ 
      s[s.size() - i - 1] = s[i];
      ans++;
    }
  }

  cout << ans;
}
  

