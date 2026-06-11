#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  ll s;cin>>s;
  ll sh=s/1000000000;
  ll mar=s%1000000000;
  if(mar!=0)
  {
    sh++;
    mar=1000000000-mar;
  }
  printf("0 0 1000000000 1 %lld %lld\n", mar, sh);
} 
