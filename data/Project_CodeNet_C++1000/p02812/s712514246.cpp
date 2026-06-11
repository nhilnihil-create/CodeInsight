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
int ans=0;
for(int i=0;i+2<n;i++)
{
if(s.substr(i,3)=="ABC")
{
ans++;
}
}
cout<<ans<<endl;
}