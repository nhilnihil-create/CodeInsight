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
string s;
cin>>s;
n%=26;
for(int i=0;i<s.length();i++)
{
s[i]+=n;
if(s[i]>'Z')
{
s[i]='A'+(s[i]-'Z'-1);
}
}
cout<<s;
}