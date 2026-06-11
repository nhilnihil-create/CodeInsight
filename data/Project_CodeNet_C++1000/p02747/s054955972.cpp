#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  string hi = "";
  bool can = false;
  rep(i,5){
    hi += "hi";
    if(hi == s) {
      can = true;
      break;
    }    
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
