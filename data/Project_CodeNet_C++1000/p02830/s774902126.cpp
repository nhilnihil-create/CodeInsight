#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  string ans="";
  int i=0,j=0;
  while(i<n||j<n)
  {
    ans.push_back(s[i]);
    ans.push_back(t[j]);
    i++;j++;}
  cout<<ans<<endl;}