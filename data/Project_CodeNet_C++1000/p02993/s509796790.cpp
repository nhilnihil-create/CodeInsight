#include<bits/stdc++.h>
using namespace std;
int main() {
  string s,ans="Good";
  int i;
  cin>>s;
  for(i=1;i<4;i++) if(s.at(i)==s.at(i-1)) ans="Bad";
  cout<<ans<<endl;
}