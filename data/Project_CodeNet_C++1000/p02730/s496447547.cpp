#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  string s; cin >> s;
  int n = s.size();
  
  bool can = true;
  rep(i, (n+1)/4){
    if(s[i]!=s[(n-3)/2-i] || s[i]!=s[(n+1)/2+i] || s[i]!=s[n-1-i]) can = false;
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  
  return 0;
}
