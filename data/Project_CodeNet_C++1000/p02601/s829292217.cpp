/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int k;
cin>>k;
string ans="Yes";
while(b<=a)
{
b*=2;
k--;
}
if(k<0)
{
ans="No";
}
else
{
while(c<=b)
{
c*=2;
k--;
}
if(k<0)
{
ans="No";
}
}
cout<<ans<<endl;
}