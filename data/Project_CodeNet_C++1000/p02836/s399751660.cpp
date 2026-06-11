#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ans = 0;
  string s;
  cin >> s;
  for(int i=0;i<(s.size()+1)/2;i++){
    if(s.at(i) != s.at(s.size()-1-i))
      ans++;
  }
  cout << ans << endl;
}