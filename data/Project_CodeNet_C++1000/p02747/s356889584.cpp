#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,q,a,b;
string s;
int main(){
  cin>>s;
  if(s.size()&1)return cout<<"No",0;
  for(a=0;a<s.size()-1;a+=2){
    if(s[a]!='h'||s[a+1]!='i')return cout<<"No",0;
  }
  cout<<"Yes";
}