#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  char c=s[0];
  bool b=true;
  for(int i=1; i<4; i++){
    if(c==s[i]){b=false; break;}
    c=s[i];
  }
  if(b) cout << "Good";
  else cout << "Bad";
  return 0;
}