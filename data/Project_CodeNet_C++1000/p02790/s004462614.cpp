#include<bits/stdc++.h>
using namespace std;
int main(void){
  string a,b; cin>>a>>b;
  int c=stoi(a),d=stoi(b);
  string s1,s2;
  for(int i=0; i<c; ++i) s1+=b;
  for(int i=0; i<d; ++i) s2+=a;
  if(s1<s2) cout<<s1; else cout<<s2;
  return 0;
}