#include<bits/stdc++.h>
using namespace std;






int main(){
  string s;
  while(getline(cin,s)){
    if(s=="."){break;}
  int k=0,m=0;
  int count=0;
  stack<int>  a;
  a.push(0);
  bool j=true;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('){k++; a.push(1);}
    if(s[i]==')'){k--; if(a.top()!=1){j=false; break;} a.pop();}
    if(s[i]=='['){m++; a.push(2);}
    if(s[i]==']'){m--; if(a.top()!=2){j=false; break;} a.pop();}
  }
  if(k!=0 || m!=0){j=false;}
  if(j){cout<<"yes"<<endl;}
  else{cout<<"no"<<endl;}
  
  }
  
  return 0;
}

