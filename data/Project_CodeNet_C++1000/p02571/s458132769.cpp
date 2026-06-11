#include <bits/stdc++.h>
using namespace std;
int main(){
  string s, t;
  cin >> s >> t;
  int ans = s.size();
  for(int i=0; i<=s.size() - t.size(); i++){
    int cnt = 0;
    for(int j=0; j<t.size(); j++){
      if(s[i + j] != t[j]) cnt++;
    }
    ans = min(cnt, ans);
  }
  cout << ans << endl;
}