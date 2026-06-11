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
string ans="No";
for(int i=1;i<=9;i++)
{
if(n%i==0 && n/i<=9)
{
ans="Yes";
break;
}
}
cout<<ans;
}