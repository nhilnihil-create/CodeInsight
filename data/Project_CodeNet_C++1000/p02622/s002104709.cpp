#include<iostream>
using namespace std;
typedef long long int ll;
typedef char c;
int main()
{
 ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll x;
  string s,t;
  cin>>s>>t;
  x=s.size();
  ll l=0;
  for(ll i=0;i<x;i++)
  {
    if(s[i]==t[i]);
    else
      l++;
  }
  cout<<l<<"\n";
  return 0;
}  