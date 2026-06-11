#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T;
  int ans = 0;
  cin >> S >> T;
  int size = S.size();
  char s,t;
  for(int i = 0; i<size; i++){
    s = S.at(i);
    t = T.at(i);
    if(s != t) ans++;
  }
  cout << ans << endl;
}