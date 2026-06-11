#include<bits/stdc++.h>
using namespace std;

int main(){
  string s, tmp;
  cin >> s;
  tmp = s;
  reverse(tmp.begin(), tmp.end());
  int ans = 0;
  for(int i=0;i<s.size();i++){
    if(s[i]!=tmp[i])
      ans++;
  }
  cout << ans/2 << endl;
}