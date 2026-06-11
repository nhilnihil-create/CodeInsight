/*
h s, d't skp th si tll i's sved
 * ABC141 E
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
string s;
cin>>s;
string ans="No";
if(n%2==0)
{
if(s.substr(0,n/2)==s.substr(n/2,n/2))
{
ans="Yes";
}
}
cout<<ans;
}