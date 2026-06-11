#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans{0};
  for(int i=0;i<3;i++){
    if(s[i] == 'R') ans = 1;
  }
  for(int i=1;i<3;i++){
    if(s[i-1] == s[i] && s[i] == 'R') ans++;
  }
  cout << ans << endl;
}