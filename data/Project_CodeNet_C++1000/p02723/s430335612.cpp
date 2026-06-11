#include <bits/stdc++.h>
using namespace std;

int main() {
  string Str;
  getline(cin, Str);
  bool tf = Str[2] == Str[3];
  bool ff = Str[4] == Str[5];
  if(tf * ff ){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;
  }
}