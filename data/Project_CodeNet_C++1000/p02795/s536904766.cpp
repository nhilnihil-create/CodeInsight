#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll h,w,n;cin>>h>>w>>n;ll x=max(h,w);ll res=ceil(1.0*n/x);
  cout<<res;
}