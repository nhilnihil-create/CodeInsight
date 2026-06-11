#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string a,b;
cin>>a>>b;
if(a<=b)
{
for(int i=0;i<stoi(b);i++)
{
cout<<a;
}
}
else
{
for(int i=0;i<stoi(a);i++)
{
cout<<b;
}
}
}