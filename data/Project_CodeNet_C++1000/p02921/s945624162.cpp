#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  int a;
  if(s[0]==t[0])a++;
  if(s[1]==t[1])a++;
  if(s[2]==t[2])a++;
  cout<<a<<endl;
}