#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s.back()!='s'){s=s+'s';}
  else {s=s+"es";}
  cout << s;
  return 0;
}