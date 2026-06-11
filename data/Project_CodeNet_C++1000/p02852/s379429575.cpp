#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m;
  bool b=false;
  string s;
  vector<long> ans;
  cin >> n >> m >> s;
  while(n>0) {
    for(long i=min(n,m);true;i--) {
      if(i==0) {
        b=true;
        break;
      }
      if(s[n-i]=='0') {
        n-=i;
        ans.push_back(i);
        break;
      }
    }
    if(b) break;
  }
  if(b) cout << -1;
  else for(long i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
  cout << endl;
}