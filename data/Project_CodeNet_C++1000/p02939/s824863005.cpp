#include <bits/stdc++.h>
using namespace std;
int n,i,j,a,b,c,x,y,z,k;
string s,s1,s2;
int main(){
  cin>>s;
  s1=s[0];
  for(i=1,c=1;i<s.size();i++,c++){
    s2=s[i];
    if(s1==s2){
      if(i==s.size()-1)c--;
      i++,s2+=s[i];
    }
    s1=s2;
  }
  cout<<c;
}