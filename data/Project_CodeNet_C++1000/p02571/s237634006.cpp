#include <bits/stdc++.h>
using namespace std;


int main() {
  string s,t;
  cin >> s >> t;
  
  int slen=s.size();
  int tlen=t.size();
  
  int ans=tlen;
  for(int i=0; i<=slen-tlen; i++){
    int diff=0;
    for(int j=0; j<tlen; j++){
      diff += s[i+j]!=t[j];
    }
    ans = min(ans,diff);
  }
  cout << ans << endl;
}