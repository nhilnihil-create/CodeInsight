#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  string s;
  int q;
  cin >> s >> q;
  
  int t, f;
  int ord = 1;
  char c;
  rep(i, q){
    cin >> t;
    if(t == 1){
      if(ord) ord = 0;
      else ord = 1;
      continue;
    }
    
    cin >> f >> c;
    if(f == 1){
      if(ord) s = c + s;
      else s.push_back(c);
    }
    else{
      if(ord) s.push_back(c);
      else s = c + s;
    }
  }
  
  if(ord == 0) reverse(s.begin(), s.end());
  cout << s << endl;
  return 0;
}