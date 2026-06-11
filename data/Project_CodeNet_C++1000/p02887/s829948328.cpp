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
for(int i=0;i+1<n;i++)
{
int j=i+1;
while(s[j]==s[j-1] && j<n)
{
j++;
}
ans++;
i=j-1;
}
if(s[n-1]!=s[n-2])
{
ans++;
}
cout<<ans<<endl;
}
