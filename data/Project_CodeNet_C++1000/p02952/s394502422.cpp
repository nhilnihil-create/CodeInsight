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
int ans=0;
for(int i=1;i<=n;i++)
{
string s=to_string(i);
if(s.length()%2==1)
{
ans++;
}
}
cout<<ans;
}