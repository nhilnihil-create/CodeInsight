#include <bits/stdc++.h>
 using namespace std;


 int main() {

  int H;
  string s;
  cin >> H>>s;
  int a=0;

  for(int i=0; i<=H; i++){if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') a++;}
  cout<<a;

 }
