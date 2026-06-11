#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans=true;
  for(int i=0,l=s.size();i<l/2;i++)
    if(s.at(i)!=s.at(l-i-1))
      ans=false;
  for(int i=0,l=s.size();i<l/4+1;i++)
    if(s.at(i)!=s.at(l/2-i-1))
      ans=false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}