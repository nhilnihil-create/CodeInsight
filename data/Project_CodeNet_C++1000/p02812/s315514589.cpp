#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c=0; cin>>n;
  string s; cin>>s;
  for(int i=0;i<n;i++) if("ABC"==s.substr(i,3)) c++;
  cout<<c;
}