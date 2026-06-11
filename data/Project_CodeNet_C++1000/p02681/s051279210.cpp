#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s,t; cin >> s >> t;
  int n = s.size();
  int m = t.size();
  bool ans = true;
  if(n != m-1)ans = false;
  for(int i = 0; i < n; i++){
    if(s[i]==t[i])continue;
    else ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
  