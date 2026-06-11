#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  string s; cin>>s;
  string l,r;
  for(int i=0; i<(n/2); ++i) l+=s[i];
  for(int i=(n/2); i<n; ++i) r+=s[i];
  if(l==r) cout<<"Yes"; else cout<<"No";
  return 0;
}