#include<bits/stdc++.h>
using namespace std;

bool Judge(string s){
  int len = s.size();
  for (int i=0; i<len; i++){
    if (s[i] != s[len-1-i]) return false;
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  string s1 = s.substr(0,(s.size()-1)/2);
  string s2 = s.substr((s.size()+1)/2, (s.size()-1)/2);
  //cout << s1 << endl;
  //cout << s2 << endl;
  if (Judge(s1)==true && Judge(s2)==true && Judge(s)) cout << "Yes";
  else cout << "No";
}