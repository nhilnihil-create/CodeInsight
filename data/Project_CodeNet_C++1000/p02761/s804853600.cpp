#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  string ans;
  for(int i=0; i<n; i++) ans.push_back('X');
  
  int a; char b;
  bool check = false;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    if(ans[a-1]=='X' || ans[a-1]==b) {
      if(a==1 && b=='0' && ans.size()!=1) {check = true; break;}
      else ans[a-1]=b;
    }
    else {check = true; break;}
  }
  
  if(check) cout << "-1" << endl;
  else {
    for(int i=0; i<n; i++) {
      if(ans[i]=='X') {
        if(i==0) {
          if(ans.size()==1) ans[i]='0';
          else ans[i]='1';
        }
        else ans[i]='0';
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}