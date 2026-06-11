#include<bits/stdc++.h>
using namespace std;

int main() { 
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,nick;
  cin>>s;
  for(int i=0;i<3;i++) {
    nick+=s[i];
  }
  cout<<nick<<endl;
  return 0;
}
