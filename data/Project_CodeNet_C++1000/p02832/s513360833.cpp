/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
bool ok=0;
int k=1;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
if(a[i]==k)
{
k++;
ok=1;
}
}
if(!ok)
{
k=n+2;
}
cout<<n-k+1<<endl;
}