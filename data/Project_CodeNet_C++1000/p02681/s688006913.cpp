#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(void){
  string s, t, ans="Yes";
  int j;
  cin >> s >> t;
  j = t.size() - 1;
  rep(i,j){
    if(s[i]==t[i]) continue;
    ans="No";
  }
  cout << ans << endl;
  return 0;
}