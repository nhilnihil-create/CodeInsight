#include <bits/stdc++.h>

using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  int ans = t.length();
  for(int i = 0; i <= s.length() - t.length(); i++){
    int diff = 0;
   	for(int j = 0; j < t.length(); j++){
      if(s[i+j] != t[j])
        diff++;
    }
    ans = min(ans, diff);
  }
  cout << ans;
  return 0;
}