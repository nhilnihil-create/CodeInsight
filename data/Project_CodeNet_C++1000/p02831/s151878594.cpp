#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
  if(a==0) return b;
  else return gcd(b%a,a);
}
int32_t main()
{
  int t,n,i,j,k,l,l1;
  cin>>i>>j;
  k=gcd(i,j);
  cout<<(i*j)/k;
}