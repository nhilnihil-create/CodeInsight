#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string x;
  cin>>x;
  int ans=0;
  for(int i=0;i<s.length();i++){if(s[i]!=x[i])ans++;}
  cout<<ans<<endl;
}