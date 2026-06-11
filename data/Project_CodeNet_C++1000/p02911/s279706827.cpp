/*
hey stop, don't skip the shit till it's solved
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n,k,q;
cin>>n>>k>>q;
int a[n]={};
int h;
int sum=0;
for(int i=0;i<q;i++)
{
cin>>h;
a[h-1]++;
sum++;
}
for(int i=0;i<n;i++)
{
if(k-(sum-a[i])<=0)
{
cout<<"No"<<endl;
}
else
{
cout<<"Yes"<<endl;
}
}
}