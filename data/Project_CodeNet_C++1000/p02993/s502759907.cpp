#include <iostream>

using namespace std;

int main ()  {
  string s;
  cin>>s;
  if(s[0]==s[1]) cout<<"Bad";
  else if(s[1]==s[2]) cout<<"Bad";
  else if(s[2]==s[3]) cout<<"Bad";
  else cout<<"Good";
  
  
}
