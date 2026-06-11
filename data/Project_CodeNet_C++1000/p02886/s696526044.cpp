#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int ans=0;
int a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
for(int o=i+1;o<n;o++)
{
ans+=a[i]*a[o];
}
}
cout<<ans<<endl;
}
