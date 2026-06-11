#include<bits/stdc++.h>
using namespace std;

signed main() {
  string S; cin >> S;
  map<char,int> m;
  for(auto c : S) m[c]++;
  if(m.size()!=2) {puts("No"); return 0;}
  for(auto c : m) if(c.second != 2) {puts("No"); return 0;}
  puts("Yes");
}
