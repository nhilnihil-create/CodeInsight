#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >>s;
  int cnt = 0;
  string t,u;
  for(int i  = 0; i<s.size();i++){
    t += s[i];
    if(t!=u){
      cnt++;
      u = t;
      t = "";
    }
  }
  cout << cnt << endl;
  return 0;
}
