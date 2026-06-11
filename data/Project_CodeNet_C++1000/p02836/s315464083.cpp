#include<iostream>
using namespace std;
int main (void)
{
  int n,i;
  string s,t;
  cin>>s;
  int ans=0;
  n=s.size();
  for(i=0;i<n/2;i++){if(s[i]!=s[n-i-1]){ans++;}}
  cout<<ans;

}