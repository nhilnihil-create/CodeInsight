#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

int main(){
  string s,t; cin >> s >> t;
  bool frg= true;
  for(int i=0;i<s.length();i++){
      if(s[i]!=t[i]) frg=false;
  }
  if(frg) cout << "Yes" << endl;
  else cout << "No" << endl;
}