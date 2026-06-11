#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin>>s;
  string a="",b="";
  int ans=0;
  for(int i=0;i<s.size();i++){
    a+=s[i];
    if(a!=b){
      ans++;
      b=a;
      a="";
    }
  }
  cout<<ans<<endl;
}