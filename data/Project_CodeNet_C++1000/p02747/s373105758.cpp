#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=(s.size()%2==0);
  for(int i=0;i<s.size();i++){
    if(i%2) ans*=(s[i]=='i');
    else ans*=(s[i]=='h');
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}