#include<iostream>
#include<string>
using namespace std;

int main(){
  string s; cin >> s;
  for(auto &c: s) if(c=='?') c = 'D';
  int count = 0;
  for(auto c: s) if(c=='D') count++;
  for(int i=0;i<s.length()-1;i++) if(s[i]=='P' && s[i+1]=='D') count++;
  cout << s << endl;
  return 0;
}
