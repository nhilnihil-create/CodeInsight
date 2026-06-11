#include<bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin>>s>>t;
  int cnt=0;
  for(int i=0;i<s.size();i++)
    cnt+=(s[i]==t[i]);
  cout<<cnt;
}