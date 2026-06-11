#include <iostream>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  for (int i=0;i<s.length();i++){
    if (s[i]!=t[i]){
      cout<<"No"<<endl;
      goto loop;
    }
  }
  cout<<"Yes"<<endl;
  loop:
  return 0;
}