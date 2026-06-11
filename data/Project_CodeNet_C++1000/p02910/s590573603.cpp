#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i;
  cin>>s;
  for(i=0;i<s.length();i++){
    if((i+1)%2==1 && s.at(i)=='L') break;
    else if((i+1)%2==0 && s.at(i)=='R') break;
  }
  if(i==s.length()) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}