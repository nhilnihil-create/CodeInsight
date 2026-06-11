#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n,x;
cin>>n>>x;
int a;
int ans=0;
int s=0;
for(int i=0;i<n;i++)
{
cin>>a;
s+=a;
if(s<=x)
{
ans++;
}
}
cout<<ans+1<<endl;
}