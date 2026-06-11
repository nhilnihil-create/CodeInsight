#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
  string s;
  char ch;
  getline(cin,s);

  for(int i=0;i<s.size();i++){
    ch=s[i];
    if(islower(ch))ch=toupper(s[i]);
    else if(isupper(ch))ch=tolower(s[i]);
    cout <<ch;
  }
  cout <<endl;
}