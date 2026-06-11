#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;	cin >> s;
  bool ok=true;
  
  for(int i=0;i<s.size();i+=2){
    if(!(s[i]=='R'||s[i]=='U'||s[i]=='D')){
      ok=false;
    }
  }
  
  for(int i=1;i<s.size();i+=2){
    if(!(s[i]=='L'||s[i]=='U'||s[i]=='D')){
      ok=false; 
    }
  }
  
  
  if(ok)	cout << "Yes";
  else cout << "No";
}