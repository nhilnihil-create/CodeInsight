#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll x;cin>>x;
  if(x>=1800)
    cout<<1;
  else if(x>=1600 && x<=1799)
    cout<<2;
  else if(x>=1400 && x<=1599)
    cout<<3;
  else if(x>=1200 && x<=1399)
    cout<<4;
  else if(x>=1000 && x<=1199)
    cout<<5;
  else if(x>=800 && x<=999)
    cout<<6;
  else if(x>=600 && x<=799)
    cout<<7;
  else if(x<=599)
    cout<<8;
}