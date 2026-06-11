#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

  ll n;
  cin>>n;
  ll n1=n-n%3;
  ll n2=n-n%5;
  ll n3=n-n%15;
  ll sum=0;
 sum+=(n1/3)*(3+n1)/2;
 sum+=(n2/5)*(5+n2)/2;
 sum-=(n3/15)*(15+n3)/2;
 ll total=n*(n+1)/2;
 total-=sum;
 cout<<total<<endl;
  return 0;
}