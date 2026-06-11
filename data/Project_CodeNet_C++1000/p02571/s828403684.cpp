#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 1000000;
  string s,t;
  cin >> s >> t;

for (int i= 0; i < s.size(); i++) {
  if (i + t.size() > s.size()){
    break;
  }
  int cnt = 0;
  for (int j = 0; j < t.size(); j++){
    if (s[i+j] != t[j]) cnt++;
  }
  ans = min(ans, cnt);
}
cout << ans << endl;
}
