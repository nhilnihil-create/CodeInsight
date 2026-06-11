#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for(int i = 0; i < n; i++) cin >> s.at(i) >> t.at(i);
  string x;
  cin >> x;
  
  int ans = 0;
  bool ok = true;
  for(int i = 0; i < n; i++){
    if(s.at(i) == x){
      ok = false;
      continue;
    }
    if(ok) continue;
    ans += t.at(i);
  }
  
  cout << ans << endl;
}