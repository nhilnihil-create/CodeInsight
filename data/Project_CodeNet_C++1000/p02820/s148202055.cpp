#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,r,s,p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  long long kotae=0;
  for(int i=0;i<n;i++){
    if(i+k<n){
      if(t[i]==t[i+k]){
        t[i+k]='a';
      }
    }
    if(t[i]=='r')kotae+=p;
    else if(t[i]=='s')kotae+=r;
    else if(t[i]=='p')kotae+=s;
  }
  cout<<kotae<<endl;
  return 0;
}