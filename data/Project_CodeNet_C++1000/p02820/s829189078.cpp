#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,r,s,p;
  string t;
  cin >>n>>k>>r>>s>>p>>t;
  long long kotae=0;
  for(int i=0;i<t.size();i++){
    if(t[i]=='r')kotae+=p;
    else if(t[i]=='s')kotae+=r;
    else kotae+=s;
  }
  for(int i=0;i<t.size()-k;i++){
    if(t[i]=='r'&&t[i]==t[i+k]){
      kotae-=p;
      t[i+k]='o';
    }else if(t[i]=='s'&&t[i]==t[i+k]){
      kotae-=r;
      t[i+k]='o';
    }else if(t[i]=='p'&&t[i]==t[i+k]){
      kotae-=s;
      t[i+k]='o';
    }
  }
  cout<<kotae<<endl;
  return 0;
}
  