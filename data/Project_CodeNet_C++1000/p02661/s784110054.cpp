//ref:-  https://codeforces.com/blog/entry/78195
//also see atcoder official editorial
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
 ll n,x,y;
 cin>>n;
 ll a[n],b[n];
 for(ll i=0;i<n;i++)
 cin>>a[i]>>b[i];
 sort(a,a+n);
 sort(b,b+n);
 if(n%2)
 {
     x=a[n/2];
     y=b[n/2];
 }
 else
 {
     x=a[n/2]+a[n/2-1];
     y=b[n/2]+b[n/2-1];
 }
 cout<<(y-x)+1;
 return 0;
}