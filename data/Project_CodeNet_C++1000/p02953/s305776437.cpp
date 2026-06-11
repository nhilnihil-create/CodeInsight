/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
bool ok=1;
int mx=0;
for(int i=0;i<n;i++)
{
cin>>a[i];
if(mx-a[i]>=2)
{
ok=0;
}
mx=max(mx,a[i]);
}
cout<<(ok ? "Yes" : "No")<<endl;
}