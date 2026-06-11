#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; string s; cin >> n >> s; 
  set<string> str; 
  set<char> c0, c1, c2; 
  for(int i=0;i<n-2;i++) {
    if(c0.size() == 10) break;
    else if(c0.count(s[i])) continue;
    else {
      for(int j=i+1;j<n-1;j++) {
        if(c1.size() == 10) break;
        else if(c1.count(s[j])) continue;
        for(int k=j+1;k<n;k++) {
          if(c2.size() == 10) break;
          else if(c2.count(k)) continue;
          string tmp = ""; 
          tmp = s.substr(i, 1)+s.substr(j, 1)+s.substr(k, 1);
          str.insert(tmp);
          c0.insert(s[i]);
          c1.insert(s[j]);
          c2.insert(s[k]);   
        }
        c2.clear();
      }
      c1.clear();
    }
  }
  cout << str.size() << endl;
  return 0;
}