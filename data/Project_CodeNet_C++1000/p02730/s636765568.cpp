#include<bits/stdc++.h>
using namespace std;
string rv(string s){
  reverse(s.begin(),s.end());
  return s;
}
int main(void){
  string s,c,a; cin>>s;
  int n=s.size();
  for(int i=1; i<=(n-1)/2; ++i) c+=s[i-1];
  for(int i=(n+3)/2; i<=n; ++i) a+=s[i-1];
  if(s==rv(s)&&c==rv(c)&&a==rv(a)) cout<<"Yes"; else cout<<"No";
  return 0;
}