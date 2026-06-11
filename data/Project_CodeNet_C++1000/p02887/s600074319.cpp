#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  string s; cin>>s;
  int res=1;
  for(int i=0; i<n-1; ++i) if(s[i]!=s[i+1]) ++res;
  cout<<res;
  return 0;
}