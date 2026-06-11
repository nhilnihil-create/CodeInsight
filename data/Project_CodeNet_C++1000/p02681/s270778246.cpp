#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;
  cin>>s>>t;
  if(t.substr(0,s.length())==s)
  cout<<"Yes\n";
  else
  cout<<"No\n";
}
