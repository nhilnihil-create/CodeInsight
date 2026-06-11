#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll x,res=0;
  cin>>x;
  ll temp1=x/500;
  ll mod1=x%500;
  res+=temp1*1000;
  ll temp2=mod1/5;
  res+=temp2*5;
  cout<<res;
}