/*
hey stop, don't skip the shit till it's solved
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
string s;
cin>>s;
string ans="Yes";
for(int i=0;i<s.length();i++)
{
if((i+1)%2==0 && s[i]=='R')
{
ans="No";
}
if((i+1)%2!=0 && s[i]=='L')
{
ans="No";
}
}
cout<<ans<<endl;
}