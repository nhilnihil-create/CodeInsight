#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
  {
  string str;
  cin>>str;
  ll c=0;
  ll n=str.length();
  for(ll i=0;i<n;i++)
    {
    c+=(str[i]-'0');
    
    }
  if(c%9)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  }
