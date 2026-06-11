#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string m = "7";
  for(int i=0; i<7; i++) {
    if(stoi(m)>=n) break;
    m += "7";
  }
  
  bool rr = false;
  int ans = m.size();
  for(int i=0; i<=1000000; i++) {
    if(stoi(m)%n==0) break;
    m = to_string(stoi(m)%n)+"7";
    ans++;
    if(i==1000000) rr = true;
  }
  if(rr) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}