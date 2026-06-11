/*
hey stop, don't skip the shit till it's solved
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
n--;
int a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int b[n+1];
b[0]=a[0];
b[1]=a[0];
int ans=0;
for(int i=1;i<n;i++)
{
b[i]=min(b[i],a[i]);
b[i+1]=a[i];
}
for(int i=0;i<n+1;i++)
{
ans+=b[i];
}
cout<<ans<<endl;
}